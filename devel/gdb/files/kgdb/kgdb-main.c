/*
 * Copyright (c) 2004 Marcel Moolenaar
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "defs.h"
#include "annotate.h"
#include "interps.h"
#include "main.h"
#include "osabi.h"
#include "run-on-main-thread.h"
#include "serial.h"
#include "solib.h"

#include <err.h>
#include <paths.h>

#include "kgdb.h"

static int verbose;

static char crashdir[PATH_MAX];
static char *dumpnr;
static char *kernel;
static char *remote;
static char *vmcore;

static void
usage(void)
{

	fprintf(stderr,
	    "usage: %s [-afqvw] [-b rate] [-d crashdir] [-c core | -n dumpnr | -r device]\n"
	    "\t[kernel [core]]\n", getprogname());
	exit(1);
}

static void
kernel_from_dumpnr(const char *nr)
{
	char line[PATH_MAX], path[PATH_MAX];
	FILE *info;
	char *dir;
	struct stat st;
	int l;

	/*
	 * If there's a kernel image right here in the crash directory, then
	 * use it.  The kernel image is either called kernel.<nr> or is in a
	 * subdirectory kernel.<nr> and called kernel.  The latter allows us
	 * to collect the modules in the same place.
	 */
	snprintf(path, sizeof(path), "%s/kernel.%s", crashdir, nr);
	if (stat(path, &st) == 0) {
		if (S_ISREG(st.st_mode)) {
			kernel = strdup(path);
			return;
		}
		if (S_ISDIR(st.st_mode)) {
			snprintf(path, sizeof(path), "%s/kernel.%s/kernel",
			    crashdir, nr);
			if (stat(path, &st) == 0 && S_ISREG(st.st_mode)) {
				kernel = strdup(path);
				return;
			}
		}
	}

	/*
	 * No kernel image here.  Parse the dump header.  The kernel object
	 * directory can be found there and we probably have the kernel
	 * image still in it.  The object directory may also have a kernel
	 * with debugging info (called either kernel.full or kernel.debug).
	 * If we have a debug kernel, use it.
	 */
	snprintf(path, sizeof(path), "%s/info.%s", crashdir, nr);
	info = fopen(path, "r");
	if (info == NULL) {
		warn("%s", path);
		return;
	}
	while (fgets(line, sizeof(line), info) != NULL) {
		l = strlen(line);
		if (l > 0 && line[l - 1] == '\n')
			line[--l] = '\0';
		if (strncmp(line, "    ", 4) == 0) {
			fclose(info);
			dir = strchr(line, ':');
			dir = (dir == NULL) ? line + 4 : dir + 1;

			/*
			 * Check for kernel.full first as if it exists
			 * kernel.debug will also exist, but will only
			 * contain debug symbols and not be recognized
			 * as a valid kernel by the osabi sniffer.
			 */
			snprintf(path, sizeof(path), "%s/kernel.full", dir);
			if (stat(path, &st) == 0 && S_ISREG(st.st_mode)) {
				kernel = strdup(path);
				return;
			}
			snprintf(path, sizeof(path), "%s/kernel.debug", dir);
			if (stat(path, &st) == 0 && S_ISREG(st.st_mode)) {
				kernel = strdup(path);
				return;
			}
			snprintf(path, sizeof(path), "%s/kernel", dir);
			if (stat(path, &st) == 0 && S_ISREG(st.st_mode)) {
				kernel = strdup(path);
				return;
			}
			return;
		}
	}
	fclose(info);
}

/*
 * Remote targets can support any number of syntaxes and we want to
 * support them all with one addition: we support specifying a device
 * node for a serial device without the "/dev/" prefix.
 *
 * What we do is to stat(2) the existing remote target first.  If that
 * fails, we try it with "/dev/" prepended.  If that succeeds we use
 * the resulting path, otherwise we use the original target.  If
 * either stat(2) succeeds make sure the file is either a character
 * device or a FIFO.
 */
static void
verify_remote(void)
{
	char path[PATH_MAX];
	struct stat st;

	if (stat(remote, &st) != 0) {
		snprintf(path, sizeof(path), "/dev/%s", remote);
		if (stat(path, &st) != 0)
			return;
		free(remote);
		remote = strdup(path);
	}
	if (!S_ISCHR(st.st_mode) && !S_ISFIFO(st.st_mode))
		errx(1, "%s: not a special file, FIFO or socket", remote);
}

static void
add_arg(struct captured_main_args *args, char const *arg)
{

	args->argc++;
	args->argv = (char **)reallocf(args->argv, (args->argc + 1) *
	    sizeof(char *));
	if (args->argv == NULL)
		err(1, "Out of memory building argument list");
	args->argv[args->argc] = (char *)arg;
}

int
main(int argc, char *argv[])
{
	char path[PATH_MAX];
	struct stat st;
	struct captured_main_args args;
	char *s;
	int a, ch, writeable;

	dumpnr = NULL;
	writeable = 0;

	strlcpy(crashdir, "/var/crash", sizeof(crashdir));
	s = getenv("KGDB_CRASH_DIR");
	if (s != NULL)
		strlcpy(crashdir, s, sizeof(crashdir));

	/* Convert long options into short options. */
	for (a = 1; a < argc; a++) {
		s = argv[a];
		if (s[0] == '-') {
			s++;
			/* Long options take either 1 or 2 dashes. */
			if (s[0] == '-')
				s++;
			if (strcmp(s, "quiet") == 0)
				argv[a] = (char *)"-q";
			else if (strcmp(s, "fullname") == 0)
				argv[a] = (char *)"-f";
		}
	}

	kgdb_quiet = 0;
	memset (&args, 0, sizeof args);
	args.interpreter_p = INTERP_CONSOLE;
	args.argv = (char **)xmalloc(sizeof(char *));
	args.argv[0] = argv[0];

	while ((ch = getopt(argc, argv, "ab:c:d:fn:qr:vw")) != -1) {
		switch (ch) {
		case 'a':
			annotation_level++;
			break;
		case 'b': {
			int i;
			char *p;

			i = strtol(optarg, &p, 0);
			if (*p != '\0' || p == optarg)
				warnx("warning: could not set baud rate to `%s'.\n",
				    optarg);
			else
				baud_rate = i;
			break;
		}
		case 'c':	/* use given core file. */
			if (vmcore != NULL) {
				warnx("option %c: can only be specified once",
				    optopt);
				usage();
				/* NOTREACHED */
			}
			vmcore = strdup(optarg);
			break;
		case 'd':	/* lookup dumps in given directory. */
			strlcpy(crashdir, optarg, sizeof(crashdir));
			break;
		case 'f':
			annotation_level = 1;
			break;
		case 'n':	/* use dump with given number. */
			dumpnr = optarg;
			break;
		case 'q':
			kgdb_quiet = 1;
			add_arg(&args, "-q");
			break;
		case 'r':	/* use given device for remote session. */
			if (remote != NULL) {
				warnx("option %c: can only be specified once",
				    optopt);
				usage();
				/* NOTREACHED */
			}
			remote = strdup(optarg);
			break;
		case 'v':	/* increase verbosity. */
			verbose++;
			break;
		case 'w':	/* core file is writeable. */
			writeable = 1;
			break;
		case '?':
		default:
			usage();
		}
	}

	if (((vmcore != NULL) ? 1 : 0) + ((dumpnr != NULL) ? 1 : 0) +
	    ((remote != NULL) ? 1 : 0) > 1) {
		warnx("options -c, -n and -r are mutually exclusive");
		usage();
		/* NOTREACHED */
	}

	if (verbose > 1)
		warnx("using %s as the crash directory", crashdir);

	if (argc > optind)
		kernel = strdup(argv[optind++]);

	if (argc > optind && (dumpnr != NULL || remote != NULL)) {
		warnx("options -n and -r do not take a core file. Ignored");
		optind = argc;
	}

	if (dumpnr != NULL) {
		snprintf(path, sizeof(path), "%s/vmcore.%s", crashdir, dumpnr);
		if (stat(path, &st) == -1)
			err(1, "%s", path);
		if (!S_ISREG(st.st_mode))
			errx(1, "%s: not a regular file", path);
		vmcore = strdup(path);
	} else if (remote != NULL) {
		verify_remote();
	} else if (argc > optind) {
		if (vmcore == NULL)
			vmcore = strdup(argv[optind++]);
		if (argc > optind)
			warnx("multiple core files specified. Ignored");
	} else if (vmcore == NULL && kernel == NULL) {
		vmcore = strdup(_PATH_MEM);
		kernel = strdup(getbootfile());
	}

	if (verbose) {
		if (vmcore != NULL)
			warnx("core file: %s", vmcore);
		if (remote != NULL)
			warnx("device file: %s", remote);
		if (kernel != NULL)
			warnx("kernel image: %s", kernel);
	}

	/* A remote target requires an explicit kernel argument. */
	if (remote != NULL && kernel == NULL) {
		warnx("remote debugging requires a kernel");
		usage();
		/* NOTREACHED */
	}

	/* If we don't have a kernel image yet, try to find one. */
	if (kernel == NULL) {
		if (dumpnr != NULL)
			kernel_from_dumpnr(dumpnr);

		if (kernel == NULL)
			errx(1, "couldn't find a suitable kernel image");
		if (verbose)
			warnx("kernel image: %s", kernel);
	}

	/* Set an alternate prompt. */
	add_arg(&args, "-iex");
	add_arg(&args, "set prompt (kgdb) ");

	/* Change osabi to assume a FreeBSD kernel. */
	add_arg(&args, "-iex");
	add_arg(&args, "set osabi FreeBSD/kernel");

	/* Open the vmcore if requested. */
	if (vmcore != NULL) {
		add_arg(&args, "-ex");
		if (asprintf(&s, "target vmcore %s%s", writeable ? "-w " : "",
		    vmcore) < 0)
			err(1, "couldn't build command line");
		add_arg(&args, s);
	}

	/* Open the remote target if requested. */
	if (remote != NULL) {
		add_arg(&args, "-ex");
		if (asprintf(&s, "target remote %s", remote) < 0)
			err(1, "couldn't build command line");
		add_arg(&args, s);
	}

	add_arg(&args, kernel);

	/* The libgdb code uses optind too. Reset it... */
	optind = 0;

	/* Terminate argv list. */
	add_arg(&args, NULL);

	gdb_assert (is_main_thread ());
	return (gdb_main(&args));
}

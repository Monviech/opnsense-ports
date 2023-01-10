PORTNAME=	ruff
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.198
PORTREVISION=	1
CATEGORIES=	devel python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extremely fast Python linter, written in Rust
WWW=		https://github.com/charliermarsh/ruff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	charliermarsh

CARGO_CRATES=	adler-1.0.2 \
		ahash-0.7.6 \
		aho-corasick-0.7.20 \
		android_system_properties-0.1.5 \
		anes-0.1.6 \
		annotate-snippets-0.6.1 \
		annotate-snippets-0.9.1 \
		anyhow-1.0.68 \
		ascii-1.1.0 \
		ascii-canvas-3.0.0 \
		assert_cmd-2.0.7 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		base64-0.13.1 \
		bincode-1.3.3 \
		bit-set-0.5.3 \
		bit-vec-0.6.3 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		bstr-1.1.0 \
		bumpalo-3.11.1 \
		cachedir-0.3.0 \
		cast-0.3.0 \
		cc-1.0.78 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chic-1.2.2 \
		chrono-0.4.23 \
		chunked_transfer-1.4.0 \
		ciborium-0.2.0 \
		ciborium-io-0.2.0 \
		ciborium-ll-0.2.0 \
		clap-3.2.23 \
		clap-4.0.32 \
		clap_complete-4.0.7 \
		clap_complete_command-0.4.0 \
		clap_complete_fig-4.0.2 \
		clap_derive-4.0.21 \
		clap_lex-0.2.4 \
		clap_lex-0.3.0 \
		clearscreen-1.0.10 \
		codegen-0.2.0 \
		codespan-reporting-0.11.1 \
		colored-2.0.0 \
		common-path-1.0.0 \
		configparser-3.0.2 \
		console-0.15.2 \
		console_error_panic_hook-0.1.7 \
		console_log-0.2.0 \
		core-foundation-sys-0.8.3 \
		crc32fast-1.3.2 \
		criterion-0.4.0 \
		criterion-plot-0.5.0 \
		crossbeam-channel-0.5.6 \
		crossbeam-deque-0.8.2 \
		crossbeam-epoch-0.9.13 \
		crossbeam-utils-0.8.14 \
		crunchy-0.2.2 \
		cxx-1.0.85 \
		cxx-build-1.0.85 \
		cxxbridge-flags-1.0.85 \
		cxxbridge-macro-1.0.85 \
		diff-0.1.13 \
		difflib-0.4.0 \
		directories-4.0.1 \
		dirs-2.0.2 \
		dirs-4.0.0 \
		dirs-next-2.0.0 \
		dirs-sys-0.3.7 \
		dirs-sys-next-0.1.2 \
		doc-comment-0.3.3 \
		dyn-clone-1.0.10 \
		either-1.8.0 \
		ena-0.14.0 \
		encode_unicode-0.3.6 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		fastrand-1.8.0 \
		fern-0.6.1 \
		filetime-0.2.19 \
		fixedbitset-0.4.2 \
		flate2-1.0.25 \
		fnv-1.0.7 \
		form_urlencoded-1.1.0 \
		fsevent-sys-4.1.0 \
		getrandom-0.1.16 \
		getrandom-0.2.8 \
		glob-0.3.0 \
		globset-0.4.9 \
		half-1.8.2 \
		hashbrown-0.12.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		hermit-abi-0.2.6 \
		hexf-parse-0.2.1 \
		iana-time-zone-0.1.53 \
		iana-time-zone-haiku-0.1.1 \
		idna-0.3.0 \
		ignore-0.4.18 \
		indexmap-1.9.2 \
		inotify-0.9.6 \
		inotify-sys-0.1.5 \
		insta-1.23.0 \
		instant-0.1.12 \
		io-lifetimes-1.0.3 \
		is-terminal-0.4.2 \
		itertools-0.10.5 \
		itoa-1.0.5 \
		joinery-2.1.0 \
		js-sys-0.3.60 \
		kqueue-1.0.7 \
		kqueue-sys-1.0.3 \
		lalrpop-0.19.8 \
		lalrpop-util-0.19.8 \
		lazy_static-1.4.0 \
		lexical-parse-float-0.8.5 \
		lexical-parse-integer-0.8.6 \
		lexical-util-0.8.5 \
		libc-0.2.139 \
		link-cplusplus-1.0.8 \
		linked-hash-map-0.5.6 \
		linux-raw-sys-0.1.4 \
		lock_api-0.4.9 \
		log-0.4.17 \
		lz4_flex-0.9.5 \
		matches-0.1.9 \
		memchr-2.5.0 \
		memoffset-0.7.1 \
		miniz_oxide-0.6.2 \
		mio-0.8.5 \
		natord-1.0.9 \
		new_debug_unreachable-1.0.4 \
		nextest-workspace-hack-0.1.0 \
		nix-0.24.3 \
		nohash-hasher-0.2.0 \
		nom-5.1.2 \
		notify-5.0.0 \
		num-bigint-0.4.3 \
		num-complex-0.4.2 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		num_cpus-1.15.0 \
		once_cell-1.16.0 \
		oorandom-11.1.3 \
		os_str_bytes-6.4.1 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.5 \
		paste-1.0.11 \
		path-absolutize-3.0.14 \
		path-dedot-3.0.18 \
		peg-0.8.1 \
		peg-macros-0.8.1 \
		peg-runtime-0.8.1 \
		percent-encoding-2.2.0 \
		petgraph-0.6.2 \
		phf-0.8.0 \
		phf-0.10.1 \
		phf_codegen-0.8.0 \
		phf_codegen-0.10.0 \
		phf_generator-0.8.0 \
		phf_generator-0.10.0 \
		phf_shared-0.8.0 \
		phf_shared-0.10.0 \
		pico-args-0.4.2 \
		plotters-0.3.4 \
		plotters-backend-0.3.4 \
		plotters-svg-0.3.3 \
		ppv-lite86-0.2.17 \
		precomputed-hash-0.1.1 \
		predicates-2.1.4 \
		predicates-core-1.0.5 \
		predicates-tree-1.0.7 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.49 \
		quick-junit-0.3.2 \
		quick-xml-0.26.0 \
		quote-1.0.23 \
		radium-0.7.0 \
		rand-0.7.3 \
		rand-0.8.5 \
		rand_chacha-0.2.2 \
		rand_chacha-0.3.1 \
		rand_core-0.5.1 \
		rand_core-0.6.4 \
		rand_hc-0.2.0 \
		rand_pcg-0.2.1 \
		rayon-1.6.1 \
		rayon-core-1.10.1 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		regex-1.7.0 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.28 \
		remove_dir_all-0.5.3 \
		ring-0.16.20 \
		ropey-1.5.0 \
		rustc-hash-1.1.0 \
		rustix-0.36.5 \
		rustls-0.20.7 \
		rustversion-1.0.11 \
		ryu-1.0.12 \
		same-file-1.0.6 \
		schemars-0.8.11 \
		schemars_derive-0.8.11 \
		scoped-tls-1.0.1 \
		scopeguard-1.1.0 \
		scratch-1.0.3 \
		sct-0.7.0 \
		semver-1.0.16 \
		serde-1.0.151 \
		serde-wasm-bindgen-0.4.5 \
		serde_derive-1.0.151 \
		serde_derive_internals-0.26.0 \
		serde_json-1.0.91 \
		shellexpand-3.0.0 \
		similar-2.2.1 \
		siphasher-0.3.10 \
		smallvec-1.10.0 \
		smawk-0.3.1 \
		spin-0.5.2 \
		static_assertions-1.1.0 \
		str_indices-0.4.1 \
		string_cache-0.8.4 \
		strsim-0.10.0 \
		strum-0.24.1 \
		strum_macros-0.24.3 \
		syn-1.0.107 \
		tempfile-3.3.0 \
		term-0.7.0 \
		termcolor-1.1.3 \
		terminal_size-0.1.17 \
		terminfo-0.7.3 \
		termtree-0.4.0 \
		test-case-2.2.2 \
		test-case-macros-2.2.2 \
		textwrap-0.16.0 \
		thiserror-1.0.38 \
		thiserror-impl-1.0.38 \
		thread_local-1.1.4 \
		time-0.1.45 \
		tiny-keccak-2.0.2 \
		tinytemplate-1.2.1 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.0 \
		titlecase-2.2.1 \
		toml-0.5.10 \
		twox-hash-1.6.3 \
		unic-char-property-0.9.0 \
		unic-char-range-0.9.0 \
		unic-common-0.9.0 \
		unic-emoji-char-0.9.0 \
		unic-ucd-category-0.9.0 \
		unic-ucd-ident-0.9.0 \
		unic-ucd-version-0.9.0 \
		unicode-bidi-0.3.8 \
		unicode-ident-1.0.6 \
		unicode-linebreak-0.1.4 \
		unicode-normalization-0.1.22 \
		unicode-width-0.1.10 \
		unicode-xid-0.2.4 \
		unicode_names2-0.5.1 \
		untrusted-0.7.1 \
		update-informer-0.5.0 \
		ureq-2.5.0 \
		url-2.3.1 \
		uuid-1.2.2 \
		version_check-0.9.4 \
		volatile-0.3.0 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.83 \
		wasm-bindgen-backend-0.2.83 \
		wasm-bindgen-futures-0.4.33 \
		wasm-bindgen-macro-0.2.83 \
		wasm-bindgen-macro-support-0.2.83 \
		wasm-bindgen-shared-0.2.83 \
		wasm-bindgen-test-0.3.33 \
		wasm-bindgen-test-macro-0.3.33 \
		web-sys-0.3.60 \
		webpki-0.22.0 \
		webpki-roots-0.22.6 \
		which-4.3.0 \
		widestring-0.5.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.42.0 \
		yaml-rust-0.4.5 \
		yansi-term-0.1.2 \
		rustpython-ast,rustpython-common,rustpython-compiler-core,rustpython-parser@git+https://github.com/RustPython/RustPython.git?rev=68d26955b3e24198a150315e7959719b03709dee\#68d26955b3e24198a150315e7959719b03709dee \
		libcst,libcst_derive@git+https://github.com/charliermarsh/LibCST?rev=f2f0b7a487a8725d161fe8b3ed73a6758b21e177\#f2f0b7a487a8725d161fe8b3ed73a6758b21e177

PLIST_FILES=	bin/${PORTNAME}

PORTSCOUT=	limit:^.*0\.0\.2[56789].* # don't report before 0.0.25x+

.include <bsd.port.mk>
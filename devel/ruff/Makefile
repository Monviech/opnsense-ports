PORTNAME=	ruff
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.5
CATEGORIES=	devel python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extremely fast Python linter, written in Rust
WWW=		https://github.com/charliermarsh/ruff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: evaluation of constant value failed, see https://github.com/briansmith/ring/issues/2006

BUILD_DEPENDS=	gmake:devel/gmake

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	charliermarsh

#CARGO_BUILD_ARGS=	--package=file://${WRKSRC}/crates/ruff_cli
CARGO_INSTALL_PATH=	crates/ruff_cli

PROGS=		ruff \
		ruff_dev \
		ruff_python_formatter

PLIST_FILES=	${PROGS:S/^/bin\//}

PORTSCOUT=	limit:^.*0\.0\.2[56789].* # don't report before 0.0.25x+

do-install:
	# workaround for error: found a virtual manifest at `xx` instead of a package manifest
.for p in ${PROGS}
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/*/release/${p} \
		${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>

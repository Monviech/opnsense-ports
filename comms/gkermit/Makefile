PORTNAME=	gkermit
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.kermitproject.org/kermit/archives/
DISTNAME=	gku100

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File transfer utility using the kermit protocol
WWW=		http://www.columbia.edu/kermit/gkermit.html

NO_WRKSUBDIR=	yes

ALL_TARGET=	posix
MAKEFILE=	makefile

OPTIONS_DEFINE=	DOCS

CFLAGS+=	-DERRNO_H

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gkermit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gkermit.nr ${STAGEDIR}${PREFIX}/share/man/man1/gkermit.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/gkermit.txt

.include <bsd.port.mk>

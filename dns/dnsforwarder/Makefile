PORTNAME=	dnsforwarder
PORTVERSION=	6.1.15
PORTEPOCH=	1
CATEGORIES=	dns

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple DNS forwarder
WWW=		https://github.com/holmium/dnsforwarder

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Unfetchable
DEPRECATED=	Abandoned, upstream repo is removed
EXPIRATION_DATE=2024-05-31

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		localbase

USE_GITHUB=	yes
GH_ACCOUNT=	holmium

PLIST_FILES=	bin/dnsforwarder
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

.include <bsd.port.mk>

PORTNAME=	triplane
PORTVERSION=	1.08.r20130224
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		SF/${PORTNAME}
DISTNAME=	${PORTNAME}-classic-${PORTVERSION}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Port of the original Triplane Turmoil game
WWW=		https://triplane.sourceforge.net/

LICENSE=	GPLv3

USES=		gmake sdl
USE_SDL=	sdl mixer

WRKSRC=		${WRKDIR}/${DISTNAME}

CFLAGS+=	-DTRIPLANE_DATA=\\\"${DATADIR}\\\"
MAKE_ENV=	DATADIR="${DATADIR}"

# ALL_TARGET="depend all" would not work in -jX case due to races
pre-build:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_WRKSRC} ${MAKE_ARGS} depend

.include <bsd.port.mk>

PORTNAME=	ifstated
PORTVERSION=	5.1
PORTREVISION=	4
PORTEPOCH=	3
CATEGORIES=	net
MASTER_SITES=	LOCAL/tobik \
		http://pkg.tobik.me/distfiles/ \
		http://christianserving.org/ports/net/ifstated/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interface state daemon

LIB_DEPENDS=	libevent.so:devel/libevent

PLIST_FILES=	etc/ifstated.conf-sample \
		sbin/ifstated \
		share/man/man5/ifstated.conf.5.gz \
		share/man/man8/ifstated.8.gz

SUB_FILES=	pkg-message

USE_RC_SUBR=	ifstated

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/ifstated.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifstated ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/ifstated.conf-sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/ifstated.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5
	${INSTALL_MAN} ${WRKSRC}/ifstated.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>

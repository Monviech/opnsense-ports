PORTNAME=	kt-paperclip
PORTVERSION=	7.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Easy upload management for ActiveRecord
WWW=		https://github.com/kreeti/kt-paperclip

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Ruby on Rails 6.1.x reaches EOL on 2024-10-01
EXPIRATION_DATE=	2024-10-24

RUN_DEPENDS=	rubygem-activemodel61>=4.2.0:databases/rubygem-activemodel61 \
		rubygem-activesupport61>=4.2.0:devel/rubygem-activesupport61 \
		rubygem-marcel>1.0.1:devel/rubygem-marcel \
		rubygem-mime-types>=0:misc/rubygem-mime-types \
		rubygem-terrapin>=0.6.0:devel/rubygem-terrapin

USES=		cpe gem magick:7,run
CPE_VENDOR=	thoughtbot

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	httplib2
PORTVERSION=	0.22.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Comprehensive HTTP client library
WWW=		https://github.com/httplib2/httplib2

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=2.4.2:devel/py-pyparsing@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	${PORTNAME}_project

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

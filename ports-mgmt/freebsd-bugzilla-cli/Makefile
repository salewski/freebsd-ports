PORTNAME=	freebsd-bugzilla-cli
PORTVERSION=	0.15.1
PORTREVISION=	1
CATEGORIES=	ports-mgmt

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Interact with the FreeBSD bugzilla instance
WWW=		https://github.com/p6m7g8/__p6-freebsd-bugzilla

LICENSE=	APACHE20

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

NO_ARCH=	yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/share/bz

USE_GITHUB=	yes
GH_ACCOUNT=	p6m7g8
GH_PROJECT=	__p6-freebsd-bugzilla
GH_TAGNAME=	e76c8b1

OPTIONS_GROUP=	BACKEND
OPTIONS_GROUP_BACKEND=	PYBUGZ
OPTIONS_DEFAULT=PYBUGZ
OPTIONS_SUB=	yes
PYBUGZ_DESC=	Use devel/pybugz for bugzilla interface

PYBUGZ_RUN_DEPENDS=	bugz:devel/pybugz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/bz ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/share/bz/*.sh ${STAGEDIR}${DATADIR}/

do-install-PYBUGZ-on:
	${MKDIR} ${STAGEDIR}${DATADIR}/pybugz/
	${INSTALL_SCRIPT} ${WRKSRC}/share/bz/pybugz/*.sh ${STAGEDIR}${DATADIR}/pybugz/

.include <bsd.port.mk>

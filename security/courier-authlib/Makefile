PORTNAME=	courier-authlib
PORTVERSION=	0.72.4
CATEGORIES?=	security mail
.if defined(PKGNAMESUFFIX)
MASTER_SITES=	SF/courier/authlib/${PORTVERSION}
.else
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty
.endif

MAINTAINER=	madpilot@FreeBSD.org
COMMENT?=	Meta-port for the courier authentication library
WWW=		https://www.Courier-MTA.org/authlib/

CONFLICTS=	courier-0.45*

.if !defined(PKGNAMESUFFIX)
RUN_DEPENDS=	courierauthconfig:security/courier-authlib-base

NO_BUILD=	yes
NO_INSTALL=	yes
PATCHDIR=	/dev/null

OPTIONS_DEFINE+=	GDBM

.include "${.CURDIR}/Makefile.opt"

.else	# !defined(PKGNAMESUFFIX)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

LIB_DEPENDS+=	libidn2.so:dns/libidn2 \
		libltdl.so:devel/libltdl \
		libcourier-unicode.so:devel/courier-unicode

USES=		iconv gmake libtool localbase perl5 pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_SUBMAKE=	yes

MAILOWN=	courier
MAILGRP=	courier
LOCALSTATEDIR=	/var
AUTHDAEMONVAR=	${LOCALSTATEDIR}/run/authdaemond

VPOPMAILDIR?=	${LOCALBASE}/vpopmail
USERDB?=	${PREFIX}/etc/userdb

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-unicode \
		--disable-static \
		--without-authcustom \
		--without-authshadow \
		--without-authpwd \
		--with-mailuser=${MAILOWN} \
		--with-mailgroup=${MAILGRP} \
		--localstatedir=${LOCALSTATEDIR} \
		--with-authdaemonvar=${AUTHDAEMONVAR} \
		--cache-file=${WRKDIR}/courier-authlib.cache

INSTALL_TARGET=	install-strip

DESCR=		${PKGDIR}/pkg-descr${PKGNAMESUFFIX}
PLIST=		${PKGDIR}/pkg-plist${PKGNAMESUFFIX:S/gdbm/db/}

PLIST_SUB+=	MAILOWN=${MAILOWN} MAILGRP=${MAILGRP}

AUTHMOD=	auth${PKGNAMESUFFIX:S/-//:S/gdbm/db/}

.if ${AUTHMOD} == authbase
RUN_DEPENDS+=	${LOCALBASE}/share/sysconftool/sysconftool:devel/sysconftool

CONFIGURE_ARGS+=--with-base --with-authpam --with-authpipe

USERS=		${MAILOWN}
GROUPS=		${MAILGRP}

OPTIONS_DEFINE+=	DOCS

DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README \
		README.authdebug.html README_authlib.html

PLIST_SUB+=	AUTHDAEMONVAR=${AUTHDAEMONVAR}
SUB_LIST+=	AUTHDAEMONVAR=${AUTHDAEMONVAR}

.if defined(WITH_AUTHPIPE_PROG)
CONFIGURE_ARGS+=--with-pipeprog=${WITH_AUTHPIPE_PROG}
.endif

.else
RUN_DEPENDS+=	courierauthconfig:security/courier-authlib-base
CONFIGURE_ARGS+=--without-base --without-authpam --without-authpipe
REMOVE_SUBDIRS+=liblock liblog
.endif

.if ${AUTHMOD} == authuserdb
.if ${PKGNAMESUFFIX} == -usergdbm
CONFLICTS+=	${PORTNAME}-userdb-0.*
LIB_DEPENDS+=	libgdbm.so:databases/gdbm
CONFIGURE_ARGS+=--with-db=gdbm
.elif ${PKGNAMESUFFIX} == -userdb
CONFLICTS+=	${PORTNAME}-usergdbm-0.*
CONFIGURE_ARGS+=--with-db=db
.endif
CONFIGURE_ARGS+=--with-userdb=${USERDB}
.else
CONFIGURE_ARGS+=--with-db=db --without-authuserdb
REMOVE_SUBDIRS+=makedat userdb
.endif

.if ${AUTHMOD} == authldap
RUN_DEPENDS+=	${LOCALBASE}/share/sysconftool/sysconftool:devel/sysconftool
OPTIONS_DEFINE+=	DOCS

DOCS=		README.ldap
USES+=	ldap
CONFIGURE_ARGS+=--with-authldap
.else
CONFIGURE_ARGS+=--without-authldap
.endif

.if ${AUTHMOD} == authmysql
RUN_DEPENDS+=	${LOCALBASE}/share/sysconftool/sysconftool:devel/sysconftool
OPTIONS_DEFINE+=	DOCS

DOCS=		README.authmysql.html README.authmysql.myownquery
USES+=		compiler:c11 mysql
CONFIGURE_ARGS+=--with-authmysql \
		--with-mysql-libs=${LOCALBASE}/lib/mysql \
		--with-mysql-includes=${LOCALBASE}/include/mysql
.else
CONFIGURE_ARGS+=--without-authmysql
.endif

.if ${AUTHMOD} == authpgsql
RUN_DEPENDS+=	${LOCALBASE}/share/sysconftool/sysconftool:devel/sysconftool
OPTIONS_DEFINE+=	DOCS

DOCS=		README.authpostgres.html
USES+=		pgsql
CONFIGURE_ARGS+=--with-authpgsql
.else
CONFIGURE_ARGS+=--without-authpgsql
.endif

.if ${AUTHMOD} == authsqlite
RUN_DEPENDS+=	${LOCALBASE}/share/sysconftool/sysconftool:devel/sysconftool
OPTIONS_DEFINE+=	DOCS

DOCS=		README.authsqlite.html
USES+=		pkgconfig sqlite
CONFIGURE_ARGS+=--with-authsqlite
.else
CONFIGURE_ARGS+=--without-authsqlite
.endif

.if ${AUTHMOD} == authvchkpw
BUILD_DEPENDS+=	${VPOPMAILDIR}/lib/libvpopmail.a:mail/vpopmail
CONFIGURE_ARGS+=--with-authvchkpw
.else
CONFIGURE_ARGS+=--without-authvchkpw
.endif

.endif	# !defined(PKGNAMESUFFIX)

.include <bsd.port.pre.mk>

.if !defined(PKGNAMESUFFIX)

.include "${.CURDIR}/Makefile.dep"

.else	# !defined(PKGNAMESUFFIX)

.if ${AUTHMOD} == authbase
USE_RC_SUBR=	courier-authdaemond

pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD}	"	Set WITH_AUTHPIPE_PROG to a program you want to use instead of"
	@${ECHO_CMD}	"	authProg for libauthpipe"
	@${ECHO_CMD}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$VPOPMAILLIBS|& -lcrypt|g;  \
		s|mysql_connect|mysql_real_connect|g; \
		s|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/*/configure \
		${WRKSRC}/configure
.for subdir in ${REMOVE_SUBDIRS}
	@${REINPLACE_CMD} -E 's,(^(ac_subdirs_all|subdirs).*)${subdir},\1,g' \
		${WRKSRC}/configure
.endfor
	@${REINPLACE_CMD} -e 's|^\(DEFAULTOPTIONS=\)""$$|\1"wbnodsn=1"|' \
		-e 's|@ALLMODULES@|authuserdb authvchkpw authpam authldap authmysql authpgsql|' \
		${WRKSRC}/authdaemonrc.in
	@${REINPLACE_CMD} -e 's:^#! @EXPECT@:#!${LOCALBASE}/bin/expect:' \
		${WRKSRC}/authsystem.passwd.in

pre-configure:
	@if [ -f "${WRKDIR}/courier-authlib.cache" -a -s "${WRKDIR}/courier-authlib.cache" ] ; then \
		${RM} "${WRKDIR}/courier-authlib.cache" ; \
	fi

post-install:
.if !empty(DOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.endif	# !defined(PKGNAMESUFFIX)

.include <bsd.port.post.mk>

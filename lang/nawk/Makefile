PORTNAME=	nawk
PORTVERSION=	20121220
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	https://BSDforge.com/projects/source/lang/nawk/
DISTNAME=	awk
DIST_SUBDIR=	nawk-${PORTVERSION}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Brian Kernighan's pattern scanning and processing language
WWW=		https://github.com/onetrueawk/awk

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	a.out
CFLAGS+=	-DHAS_ISBLANK
PLIST_FILES=	bin/nawk share/man/man1/nawk.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|awk|nawk|g' ${WRKSRC}/awk.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${STAGEDIR}${PREFIX}/bin/nawk
	${INSTALL_MAN} ${WRKSRC}/awk.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/nawk.1

.include <bsd.port.mk>

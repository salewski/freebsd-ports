PORTNAME=	java-games-suite
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	SF/javagamessuite

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Simple Java games collection
WWW=		https://sourceforge.net/projects/javagamessuite/

USES=		java

NO_ARCH=	yes

PLIST_FILES=	bin/java-games-suite \
		${JAVAJARDIR}/MM.jar \
		${JAVAJARDIR}/reversi.jar \
		${JAVAJARDIR}/Mine.jar \
		${JAVAJARDIR}/Tetris.jar \
		${JAVAJARDIR}/RT.jar \
		${JAVAJARDIR}/Number.jar
SUB_FILES=	${PORTNAME}.sh
GAMES=	MM reversi Mine Tetris RT Number

post-extract-script:
.for game in ${GAMES}
	@${ECHO_CMD} "Main-Class: ${game}" > ${WRKSRC}/${game}/MANIFEST.MF
.endfor

do-build:
.for game in ${GAMES}
	cd ${WRKSRC}/${game} && \
		${JAVAC} ${game}.java
.endfor

post-build-script:
.for game in ${GAMES}
	@cd ${WRKSRC}/${game} && \
		${JAR} -cfm ${game}.jar MANIFEST.MF ${game}.java ${game}.class
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
.for game in ${GAMES}
	${INSTALL_DATA} ${WRKSRC}/${game}/${game}.jar ${STAGEDIR}${JAVAJARDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

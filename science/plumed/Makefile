PORTNAME=	plumed
DISTVERSION=	2.9.3
PORTREVISION=	1
CATEGORIES=	science graphics
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}2/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PLUgin for MolEcular Dynamics
WWW=		https://www.plumed.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BROKEN_i386=	undefined reference to `__atomic_load'

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libblas.so:math/blas \
		libfftw3.so:math/fftw3 \
		libgsl.so:math/gsl \
		liblapack.so:math/lapack
RUN_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	gawk:lang/gawk

USES=		autoreconf compiler:c++11-lang gmake localbase pkgconfig shebangfix tar:tgz
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.sh
SHEBANG_FILES=	src/maketools/makecmd \
		src/maketools/xxd \
		regtest/scripts/check \
		regtest/scripts/run \
		regtest/scripts/what

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-python

TEST_TARGET=	check # the 'installcheck' target checks installed version
# 1 test is known to fail: https://github.com/plumed/plumed2/issues/782

BINARY_ALIAS=	make=${GMAKE} # only needed for tests

post-patch:
	@${REINPLACE_CMD} -e 's|#! /bin/bash|#! ${LOCALBASE}/bin/bash|' ${WRKSRC}/src/lib/Makefile

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/plumed/obj
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/plumed lib/plumed/plumed-runtime lib/libplumed.so lib/libplumedKernel.so

# tests as of 2.9.3: 277 tests performed, 352 tests not applicable

.include <bsd.port.mk>

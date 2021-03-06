INCLUDE_ONCE_MACRO(JPEG)

SETUP_SUPERBUILD(JPEG)

if(WIN32)
  set(JPEG_CONFIGURE_COMMAND "${SB_CMAKE_COMMAND}"
    ${SB_CMAKE_CACHE_ARGS}
    -DENABLE_SHARED=TRUE
    -DENABLE_STATIC=FALSE
    -DWITH_SIMD=FALSE
    -DWITH_TURBOJPEG=FALSE
    -DWITH_ARITH_DEC=TRUE
    -DWITH_JAVA=FALSE
    ${JPEG_SB_SRC} )

else()
  set(JPEG_CONFIGURE_COMMAND "${SB_ENV_CONFIGURE_CMD};${JPEG_SB_SRC}/configure"
    ${SB_CONFIGURE_ARGS}
    --with-arith-dec
    --without-simd
    --without-java
     )

endif()

ExternalProject_Add(JPEG
  PREFIX JPEG
  URL "http://sourceforge.net/projects/libjpeg-turbo/files/1.4.1/libjpeg-turbo-1.4.1.tar.gz"
  URL_MD5 b1f6b84859a16b8ebdcda951fa07c3f2
  SOURCE_DIR ${JPEG_SB_SRC}
  BINARY_DIR ${JPEG_SB_BUILD_DIR}
  INSTALL_DIR ${SB_INSTALL_PREFIX}
  DOWNLOAD_DIR ${DOWNLOAD_LOCATION}
  CONFIGURE_COMMAND ${JPEG_CONFIGURE_COMMAND}
  )

SUPERBUILD_PATCH_SOURCE(JPEG)

SUPERBUILD_UPDATE_CMAKE_VARIABLES(JPEG FALSE)

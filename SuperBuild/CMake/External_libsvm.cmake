INCLUDE_ONCE_MACRO(LIBSVM)

SETUP_SUPERBUILD(LIBSVM)

ExternalProject_Add(LIBSVM
  PREFIX LIBSVM
  URL "http://www.csie.ntu.edu.tw/~cjlin/libsvm/libsvm-3.20.tar.gz"
  URL_MD5 5f088e5f89da1c65b642300c9c5ea772
  BINARY_DIR ${LIBSVM_SB_BUILD_DIR}
  DOWNLOAD_DIR ${DOWNLOAD_LOCATION}
  INSTALL_DIR ${SB_INSTALL_PREFIX}
  CMAKE_CACHE_ARGS ${SB_CMAKE_CACHE_ARGS}
  CMAKE_COMMAND ${SB_CMAKE_COMMAND}
  DEPENDS ${LIBSVM_DEPENDENCIES}
  PATCH_COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_SOURCE_DIR}/patches/LIBSVM/CMakeLists.txt
  ${LIBSVM_SB_SRC}
  )

set(_SB_LIBSVM_INCLUDE_DIR ${SB_INSTALL_PREFIX}/include)
if(WIN32)
  set(_SB_LIBSVM_LIBRARY ${SB_INSTALL_PREFIX}/lib/svm.lib)
elseif(UNIX)
  set(_SB_LIBSVM_LIBRARY ${SB_INSTALL_PREFIX}/lib/libsvm${CMAKE_SHARED_LIBRARY_SUFFIX})
endif()

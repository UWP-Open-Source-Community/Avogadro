# Avogadro CMake version file - http://avogadro.cc/

set(PACKAGE_VERSION 1.2.0)

if("${PACKAGE_VERSION}" VERSION_LESS "${PACKAGE_FIND_VERSION}")
  set(PACKAGE_VERSION_COMPATIBLE FALSE)
else("${PACKAGE_VERSION}" VERSION_LESS "${PACKAGE_FIND_VERSION}")
  set(PACKAGE_VERSION_COMPATIBLE TRUE)
  if("${PACKAGE_FIND_VERSION}" STREQUAL "${PACKAGE_VERSION}")
    set(PACKAGE_VERSION_EXACT TRUE)
  endif("${PACKAGE_FIND_VERSION}" STREQUAL "${PACKAGE_VERSION}")
endif("${PACKAGE_VERSION}" VERSION_LESS "${PACKAGE_FIND_VERSION}")


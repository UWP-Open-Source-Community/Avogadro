#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "avogadro" for configuration "Release"
set_property(TARGET avogadro APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(avogadro PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/bin/avogadro.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/avogadro.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS avogadro )
list(APPEND _IMPORT_CHECK_FILES_FOR_avogadro "${_IMPORT_PREFIX}/bin/avogadro.lib" "${_IMPORT_PREFIX}/bin/avogadro.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

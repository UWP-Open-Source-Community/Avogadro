# Avogadro CMake configuration file - http://avogadro.openmolecules.net/

# If this file was found, then Avogadro has been found
set(Avogadro_FOUND 1)

set(Avogadro_VERSION_MAJOR   "1")
set(Avogadro_VERSION_MINOR   "1")
set(Avogadro_VERSION_PATCH   "1")
set(Avogadro_VERSION         "${Avogadro_VERSION_MAJOR}.${Avogadro_VERSION_MINOR}.${Avogadro_VERSION_PATCH}")

set(Avogadro_ENABLE_PYTHON   "OFF")
set(Avogadro_ENABLE_GLSL     "OFF")

set(Avogadro_INSTALL_PREFIX  "C:/Users/Marcus/build/avogadro-squared-1.1.0/prefix")
set(Avogadro_INCLUDE_DIRS    "C:/Users/Marcus/build/avogadro-squared-1.1.0/prefix/include")
set(Avogadro_LIBRARY_DIRS    "C:/Users/Marcus/build/avogadro-squared-1.1.0/prefix/bin")
set(Avogadro_LIB_SUFFIX      "")
set(Avogadro_PLUGIN_DIR      "C:/Users/Marcus/build/avogadro-squared-1.1.0/prefix/lib/avogadro/1_1")
set(Avogadro_BIN_DIRS        "C:/Users/Marcus/build/avogadro-squared-1.1.0/prefix/bin")

# Now for the use file, which contains useful functions, sets up the project
set(Avogadro_USE_FILE
    "${Avogadro_PLUGIN_DIR}/AvogadroUse.cmake")


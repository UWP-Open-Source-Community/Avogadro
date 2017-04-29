# Avogadro CMake configuration file - http://avogadro.cc/

# If this file was found, then Avogadro has been found
set(Avogadro_FOUND 1)

set(Avogadro_VERSION_MAJOR   "1")
set(Avogadro_VERSION_MINOR   "2")
set(Avogadro_VERSION_PATCH   "0")
set(Avogadro_VERSION         "${Avogadro_VERSION_MAJOR}.${Avogadro_VERSION_MINOR}.${Avogadro_VERSION_PATCH}")

set(Avogadro_ENABLE_PYTHON   "FALSE")
set(Avogadro_ENABLE_GLSL     "ON")

set(Avogadro_INSTALL_PREFIX  "C:/Program Files (x86)/Avogadro")
set(Avogadro_INCLUDE_DIRS    "C:/Program Files (x86)/Avogadro/include")
set(Avogadro_LIBRARY_DIRS    "C:/Program Files (x86)/Avogadro/bin")
set(Avogadro_LIB_SUFFIX      "")
set(Avogadro_PLUGIN_DIR      "C:/Program Files (x86)/Avogadro/lib/avogadro/1_2")
set(Avogadro_BIN_DIRS        "C:/Program Files (x86)/Avogadro/bin")

# Now for the use file, which contains useful functions, sets up the project
set(Avogadro_USE_FILE
    "${Avogadro_PLUGIN_DIR}/AvogadroUse.cmake")


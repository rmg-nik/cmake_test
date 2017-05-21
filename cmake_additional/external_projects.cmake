include(ExternalProject)

# Builds external third party projects.
# The parent script needs to define the "GLOBAL_OUTPUT_PATH" variable,
# which will be used as output directory for all *.lib, *.dll, *.a, *.so, *.pdb files.

###############################################################################
# SDL2
###############################################################################

ExternalProject_Add(
    SDL2_project

    UPDATE_COMMAND ""
    PATCH_COMMAND ""

    SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/sdl2"
    CMAKE_ARGS -DSDL_SHARED_ENABLED_BY_DEFAULT=OFF -DCMAKE_INSTALL_PREFIX=${GLOBAL_OUTPUT_PATH}/sdl2

    TEST_COMMAND ""
)

set(SDL2_LIBRARIES "SDL2")

set(SDL2_INCLUDE_DIRS "${GLOBAL_OUTPUT_PATH}/sdl2/include")
set(SDL2_LIBRARIES_DIRS "${GLOBAL_OUTPUT_PATH}/sdl2/lib")

include_directories(${SDL2_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARIES_DIRS})

set_target_properties (SDL2_project PROPERTIES
    FOLDER external
)

###############################################################################
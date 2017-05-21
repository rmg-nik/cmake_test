cmake_minimum_required (VERSION 3.5)

project (cmake_tutorial)

# Global settings
set(GLOBAL_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/install)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(MSVC)
	add_definitions(/MP)
endif(MSVC)

# Sets global output directory for single configuration (GCC)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${GLOBAL_OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${GLOBAL_OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${GLOBAL_OUTPUT_PATH})

# Sets global output directory for sub-configurations (msvc, mingw)
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${GLOBAL_OUTPUT_PATH})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${GLOBAL_OUTPUT_PATH})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${GLOBAL_OUTPUT_PATH})
endforeach(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)

# 3rdparty Libraries
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_additional/external_projects.cmake)

# Global link directories
link_directories(${GLOBAL_OUTPUT_PATH})

set(CMAKE_USER_MAKE_RULES_OVERRIDE
   ${CMAKE_CURRENT_SOURCE_DIR}/cmake_additional/c_flag_overrides.cmake)
set(CMAKE_USER_MAKE_RULES_OVERRIDE_CXX
   ${CMAKE_CURRENT_SOURCE_DIR}/cmake_additional/cxx_flag_overrides.cmake)

set(EXTERNAL_1_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/external/extern_1/include")
add_subdirectory("${CMAKE_SOURCE_DIR}/external/extern_1")

set(BOOST_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/external/boost")
add_subdirectory("${CMAKE_SOURCE_DIR}/external/boost")

set(PROJECTS_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/projects")

add_subdirectory("${CMAKE_SOURCE_DIR}/projects/some_engine")

add_subdirectory("${CMAKE_SOURCE_DIR}/projects/project_main")

# Installation
# Copies files from build directory into install directory.
#file(GLOB executables "${GLOBAL_OUTPUT_PATH}/*.exe")
#install(FILES ${executables} DESTINATION "bin")
#
#file(GLOB libraries "${GLOBAL_OUTPUT_PATH}/*.dll")
#install(FILES ${libraries} DESTINATION "bin")
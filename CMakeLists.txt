cmake_minimum_required (VERSION 3.5)

project (cmake_tutorial)

# Global settings
set(GLOBAL_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/install)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(MSVC)
	add_definitions(/MP)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:MSVCRTD.lib")
	foreach(flag_var
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
      if(${flag_var} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
      endif(${flag_var} MATCHES "/MD")
    endforeach(flag_var)
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
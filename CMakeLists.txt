# --------------------------------------------------------------------------- #
# Author:       Joey Dumont                   <joey.dumont@gmail.com>         #
# Date:         2015-09-02                                                    #
# Description:  CMake compilation instructions.                               #
# License:      CC0 - Public Domain.                                          #
#                                                                             #
# This file is part of the Zernike library. It is thus freely available and   #
# infinitely modifiable and copyable. As it is with such products, it comes   #
# with absolutely no warranty. It might even have bugs (!). If so, feel free  #
# to drop a line at the email address above, or visit:                        #
# https://github.com/valandil/zernike                                         #
# ----------------------------------------------------------------------------#

# ----------------------------------------------------------------- #
# --                 Name and version of library                 -- #
# ----------------------------------------------------------------- #
project(Zernike)
set (Zernike_VERSION_MAJOR   0)
set (Zernike_VERSION_MINOR   0)
set (Zernike_VERSION_RELEASE 1)

# ----------------------------------------------------------------- #
# --               Configuration and Dependencies                -- #
# ----------------------------------------------------------------- #
# -- CMake version and installation directory.
cmake_minimum_required(VERSION 2.8)

# -- Default installation directory.
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX /usr)
endif()

# -- Search path for CMake modules.
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
                       ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules)

# -- Compiler config.
# Configuration for the GCC compiler.
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -march=native -std=c++11")
  set (CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -O3 -Wall -march=native")
endif()

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Intel")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11")
  set (CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -O3 -std=c++11")
endif()

# ----------------------------------------------------------------- #
# --                  Compilation Instructions                   -- #
# ----------------------------------------------------------------- #
# -- Included files
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include INC_LIST)

# -- Source files
aux_source_directory (${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)

# -- Build a shared library
add_library(${PROJECT_NAME} SHARED ${SRC_LIST})

# Define the properties of the library to
# be built (version and other stuff).
set_target_properties (
  ${PROJECT_NAME}
  PROPERTIES
    VERSION   ${Zernike_VERSION_MAJOR}.${Zernike_VERSION_MINOR}.${Zernike_VERSION_RELEASE}
    SOVERSION ${Zernike_VERSION_MAJOR}.${Zernike_VERSION_MINOR}.${Zernike_VERSION_RELEASE}
)

# Link dependencies
target_link_libraries (${PROJECT_NAME} ${LIBS})

# Install directories
install (TARGETS   ${PROJECT_NAME} DESTINATION lib)
install (DIRECTORY include/ DESTINATION include)

# ----------------------------------------------------------------- #
# --                   Packaging Instructions                    -- #
# ----------------------------------------------------------------- #

# Configure and install the pkg-config file.
find_package(PkgConfig QUIET)
if (PKG_CONFIG_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/pkg/Zernike.pc.in
                 ${CMAKE_CURRENT_BINARY_DIR}/pkg/Zernike.pc @ONLY)
  install       (FILES ${CMAKE_CURRENT_BINARY_DIR}/pkg/Zernike.pc
                 DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig/)
endif(PKG_CONFIG_FOUND)

# Install the CMake Find Modules.
install (DIRECTORY   ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/
         DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/Zernike)

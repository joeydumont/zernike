# --------------------------------------------------------------------------- #
# Author:       Joey Dumont                   <joey.dumont@gmail.com>         #
# Date:         2015-09-06                                                    #
# Description:  Attempts to find the Zernike library.                         #
# License:      CC0 - Public Domain                                           #
#                                                                             #
# This CMake module attemps to find the Zernike library. Once it is done,     #
# the following will be defined:                                              #
#     - Zernike_FOUND: if system has Zernike and everything is parsed;        #
#     - Zernike_INCLUDE_DIR: folder where headers are.                        #
#     - Zernike_LIBRARY: library against which to link.                       #
#                                                                             #
# This file is part of the Zernike library. It is thus freely available and   #
# infinitely modifiable and copyable. As it is with such products, it comes   #
# with absolutely no warranty. It might even have bugs (!). If so, feel free  #
# to drop a line at the email address above, or visit:                        #
# https://github.com/valandil/zernike                                         #
# ----------------------------------------------------------------------------#

# -- LibFindMacros for convenience
# https://github.com/Tronic/cmake-modules/blob/master/LibFindMacros.cmake
include(LibFindMacros)

# -- We use pkg-config to give information about the
libfind_pkg_check_modules(Zernike_PKGCONF zernike)

find_path(Zernike_INCLUDE_DIR
  NAMES zernike
  PATHS ${Zernike_PKGCONF_INCLUDE_DIRS})

find_library(Zernike_LIBRARY
  NAMES zernike
  PATHS ${Zernike_PKGCONF_LIBRARY_DIRS}
)

# Set the include dir variables and the libraries and let libfind_process do the rest.
# NOTE: Singular variables for this library, plural for libraries this this lib depends on.
set(Zernike_PROCESS_INCLUDE Zernike_INCLUDE_DIR)
set(Zernike_PROCESS_LIB     Zernike_LIBRARY)
libfind_process(Zernike)

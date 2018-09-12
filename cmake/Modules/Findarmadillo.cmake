# --------------------------------------------------------------------------- #
# Author:       Denis Gagnon               <denis.gagnon@emt.inrs.ca>         #
# Date:         2017-06-12                                                    #
# Description:  CMake module to find armadillo.                               #
# ----

# -- LibFindMacros for convenience
# https://github.com/Tronic/cmake-modules/blob/master/LibFindMacros.cmake
include(LibFindMacros)

# Use pkg-config to get hints about paths
libfind_pkg_check_modules(armadillo_PKGCONF armadillo)

# Include dir
find_path(armadillo_INCLUDE_DIR
  NAMES armadillo
  PATHS ${armadillo_PKGCONF_INCLUDE_DIRS}
)

# Finally the library itself
find_library(armadillo_LIBRARY
    NAMES libarmadillo libarmadillo.so libarmadillo.dylib
    PATHS ${armadillo_PKGCONF_LIBRARY_DIRS}
)

# Set the include dir variables and the libraries and let libfind_process do the rest.
set(armadillo_PROCESS_INCLUDE armadillo_INCLUDE_DIR)
set(armadillo_PROCESS_LIB armadillo_LIBRARY)
libfind_process(armadillo)

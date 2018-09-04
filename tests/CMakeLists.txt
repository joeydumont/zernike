# --------------------------------------------------------------------------- #
# Author:       Joey Dumont                      <joey.dumont@gmail.com>      #
# Date created: 201-09- 04                                                    #
# Description:  CMake compilation instructions for the Zernike tests.         #
# ----------------------------------------------------------------------------#


# -- Dependency (Google Test)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(LIBS ${LIBS} ${GTEST_LIBRARIES})

# -- Output tests in directory
add_executable("UnitTest-IndexConversion" "UnitTest-IndexConversion.cpp")
target_link_libraries("UnitTest-IndexConversion" ${PROJECT_NAME} ${LIBS})
add_test(NAME "UnitTest-IndexConversion" COMMAND "UnitTest-IndexConversion")
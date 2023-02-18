cmake_minimum_required (VERSION 3.8)
project ("statFEMPP")
##############################################################################
# PACKAGES
##############################################################################
set(EIGEN3_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/eigen/" )
if(NOT EIGEN3_INCLUDE_DIR )
    message(FATAL_ERROR "Please point the variable EIGEN3_INCLUDE_DIR to the include directory of your Eigen3 installation.")
endif()
message(STATUS "    Eigen3 directory: ${EIGEN3_INCLUDE_DIR}")


set (GMSH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/gmsh/include/")
if(NOT GMSH_INCLUDE_DIR )
    message(FATAL_ERROR "Please point the variable GMSH_INCLUDE_DIR to the include directory of your GMSH installation.")
endif()
message(STATUS "    GMSH directory: ${GMSH_INCLUDE_DIR}")




##############################################################################
# HEADERS
##############################################################################
include_directories(${EIGEN3_INCLUDE_DIR})
include_directories(${GMSH_INCLUDE_DIR})


# Include sub-projects.
add_subdirectory("lib/matplotplusplus")
add_subdirectory ("statFEMPP")


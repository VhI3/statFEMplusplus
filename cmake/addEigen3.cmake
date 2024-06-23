# - Try to find Eigen3 or download it if not found
#
# This script tries to find a locally installed copy of Eigen3 (minimum version 3.3).
# If Eigen3 is not found, it will download the library from
# https://gitlab.com/libeigen/eigen
# and place it in an external folder.

# Attempt to find a local installation of Eigen3 (minimum version 3.3)
find_package(Eigen3 3.3 CONFIG)

if(EIGEN3_FOUND)
  message(STATUS "Eigen3 v${EIGEN3_VERSION_STRING} found in ${EIGEN3_INCLUDE_DIR}")
else()
  include(FetchContent)
  FetchContent_Declare(
        Eigen
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        GIT_TAG 3.3.9  # replace with a specific version or tag
        SOURCE_DIR "${PROJECT_SOURCE_DIR}/external/eigen"
        BINARY_DIR "${PROJECT_BINARY_DIR}/external/eigen-build"
    )
  FetchContent_GetProperties(Eigen)
  if(NOT eigen_POPULATED)
    FetchContent_Populate(Eigen)
    set(EIGEN3_INCLUDE_DIR ${eigen_SOURCE_DIR})
  endif()

  # Create an INTERFACE target for Eigen3
  add_library(Eigen3::Eigen INTERFACE IMPORTED)
  set_target_properties(Eigen3::Eigen PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${EIGEN3_INCLUDE_DIR}"
    )
endif()

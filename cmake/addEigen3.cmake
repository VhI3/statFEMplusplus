# CMake script to locate or fetch the Eigen3 library
#
# This script is designed to find an existing installation of the Eigen3 library on the system 
# with a minimum version requirement of 3.3. Eigen is a popular C++ template library for linear 
# algebra: matrices, vectors, numerical solvers, and related algorithms.
#
# If Eigen3 is found on the system, it will be used, and a message indicating its version and 
# include directory will be displayed. If Eigen3 is not found, the script will automatically 
# download the library from the official repository on GitLab using CMake's FetchContent module.
# 
# The downloaded library will be placed in a specified external folder within the project 
# directory, and an INTERFACE target (Eigen3::Eigen) will be created to make the library available 
# for linking and include directory configuration within the project.
#
# Key Features of this Script:
# - Ensures that a suitable version of Eigen3 is available for the project.
# - Automatically handles the acquisition of Eigen3 if it's not installed, avoiding manual 
#   download and installation steps.
# - Configures the include directories appropriately for both found and fetched instances of Eigen3.
#
# This approach keeps the project self-contained and user-friendly, reducing external dependencies 
# and easing the setup process for new developers and CI/CD environments.
#
# Note: This script uses CMake's FetchContent module, which requires CMake version 3.11 or higher.
# Ensure that FetchContent is available and that your CMake version is compatible.

# Attempt to find a local installation of Eigen3 (minimum version 3.3)
find_package(Eigen3 3.3 CONFIG)

if(EIGEN3_FOUND)
  message(STATUS "Eigen3 v${EIGEN3_VERSION_STRING} found in ${EIGEN3_INCLUDE_DIR}")
else()
  include(FetchContent)
  FetchContent_Declare(
        Eigen
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        GIT_TAG 3.3.9  # Replace with a specific version or tag if needed
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


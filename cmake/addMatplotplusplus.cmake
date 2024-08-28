# CMake script to locate or fetch the matplotplusplus library
#
# This script is designed to find an existing installation of matplotplusplus on the system. matplotplusplus 
# is a C++ plotting library inspired by MATLAB, which provides an easy way to create 2D and 3D 
# plots with a syntax similar to MATLAB and matplotlib.
#
# If matplotplusplus is found on the system, it will be used, and a message indicating its version 
# and include directory will be displayed. If matplotplusplus is not found, the script will 
# automatically download the library from its official GitHub repository using CMake's FetchContent 
# module.
#
# The downloaded library will be placed in a specified external folder within the project directory, 
# and an INTERFACE target (matplotplusplus::matplot) will be created to make the library available for 
# linking and include directory configuration within the project.
#
# Key Features of this Script:
# - Ensures that a suitable version of matplotplusplus is available for the project.
# - Automatically handles the acquisition of matplotplusplus if it's not installed, avoiding manual 
#   download and installation steps.
# - Configures the include directories appropriately for both found and fetched instances of matplotplusplus.
#
# This approach keeps the project self-contained and user-friendly, reducing external dependencies 
# and easing the setup process for new developers and CI/CD environments.
#
# Note: This script uses CMake's FetchContent module, which requires CMake version 3.11 or higher.
# Ensure that FetchContent is available and that your CMake version is compatible.

# Attempt to find matplotplusplus
# Attempt to find matplotplusplus

include(FetchContent)


FetchContent_Declare(matplotplusplus
        GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
        GIT_TAG origin/master
      SOURCE_DIR "${PROJECT_SOURCE_DIR}/external/matplotplusplus"
    )


FetchContent_GetProperties(matplotplusplus)
if(NOT matplotplusplus_POPULATED)
    FetchContent_Populate(matplotplusplus)
    add_subdirectory(${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

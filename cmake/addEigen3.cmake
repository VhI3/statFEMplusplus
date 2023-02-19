# - Try to add Eigen3 lib
#
# This module tries to find the Eigen3 lib if it is installed.
# If it is not installed, the lib will be download from 
# https://gitlab.com/libeigen/eigen
# and will be added to external folder.


# First cmake tries to find the installed Eigen with minimum version 3.3
# If it is not found, then the latest version will be downloaded and added to project.
find_package(Eigen3 3.3 REQUIRED CONFIG) # with argument "REQUIRED" doesn't work correctly.
if(TARGET Eigen3::Eigen)
    message(STATUS "VHI3 Comment: Eigen3 v${EIGEN3_VERSION_STRING} found in ${EIGEN3_INCLUDE_DIR}")
else()
    include(FetchContent)
    set(FETCHCONTENT_BASE_DIR "${PROJECT_SOURCE_DIR}/external/eigen")
    FetchContent_Declare(Eigen
            GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
            GIT_TAG origin/master)
    FetchContent_GetProperties(Eigen)
    if(NOT eigen_POPULATED)
        FetchContent_Populate(Eigen)
        add_subdirectory(${eigen_SOURCE_DIR} ${eigen_BINARY_DIR} EXCLUDE_FROM_ALL)
    endif()
endif()






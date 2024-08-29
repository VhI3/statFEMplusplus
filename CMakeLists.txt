# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.5...3.21 FATAL_ERROR)

# Project name and the type of the project (C++ project here)
project(statFEMplusplus LANGUAGES CXX)

# Add the cmake/ directory to the CMake module path (for FindEigen3.cmake)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Check if ccache is available and set it as the compiler launcher
find_program(CCACHE_PROGRAM ccache)

if(CCACHE_PROGRAM)
    message(STATUS "Found ccache: ${CCACHE_PROGRAM}")
    set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
    set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
else()
    message(STATUS "ccache not found. Continuing without ccache.")
endif()

# Set directories for output binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Directory for external libraries
set(PROJECT_EXTERNAL_LIBRARIES_DIR external)

# Include the script for adding Eigen3
include(addEigen3)
include(addMatplotplusplus)
# Enable testing
enable_testing()

# Include system paths for headers
# include_directories(/usr/include /usr/local/include /usr/include/x86_64-linux-gnu)

# Alternatively, you could add these paths to the compile flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu")

# set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

# Check if using MSVC (Visual Studio) compiler
if (MSVC)
    # Add /bigobj flag for all targets
    add_compile_options(/bigobj)
endif()

# add_subdirectory(external/matplotplusplus)
include_directories(external/exprtk)
include_directories(external/matplotplusplus)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(test)

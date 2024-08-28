# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.5...3.21 FATAL_ERROR)

# Project name and the type of the project (C++ project here)
project(statFEMplusplus LANGUAGES CXX)

# Add the cmake/ directory to the CMake module path (for FindEigen3.cmake)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

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


# add_subdirectory(external/matplotplusplus)
include_directories(external/exprtk)
include_directories(external/matplotplusplus)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(test)

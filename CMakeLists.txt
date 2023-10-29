# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.5...3.21 FATAL_ERROR)

# Project name and the type of the project (C++ project here)
project(statFEMpp LANGUAGES CXX)

# Add the cmake/ directory to the CMake module path (for FindEigen3.cmake)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Set directories for output binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Set source directory and examples directory
set(PROJECT_SOURCE_DIR src)
set(PROJECT_EXAMPLES_DIR examples)

# List of source and header files
set(PROJECT_EXAMPLES 
    ${PROJECT_EXAMPLES_DIR}/main.cpp 
    ${PROJECT_SOURCE_DIR}/Node.cpp 
    ${PROJECT_SOURCE_DIR}/Node.hpp 
    ${PROJECT_SOURCE_DIR}/Node.h
)

# Directory for external libraries
set(PROJECT_EXTERNAL_LIBRARIES_DIR external)

# Include the script for adding Eigen3
include(addEigen3)

# Define the executable target and its source files
add_executable(${PROJECT_NAME} ${PROJECT_EXAMPLES})

# Link the executable target against Eigen3
target_link_libraries(${PROJECT_NAME} 
    PUBLIC 
    Eigen3::Eigen
)

# Specify the include directories
target_include_directories(${PROJECT_NAME} 
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>  # for building
    $<INSTALL_INTERFACE:include>  # for installation
)

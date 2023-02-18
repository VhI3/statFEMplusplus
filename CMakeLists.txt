cmake_minimum_required (VERSION 3.3)
set(PROJECT_NAME statFEMpp)
set(PROJECT_SOURCE_DIR src)
set(PROJECT_EXAMPLES_DIR examples)
set(PROJECT_EXAMPLES ${PROJECT_EXAMPLES_DIR}/main.cpp)
set(PROJECT_EXTERNAL_LIBRARIES_DIR external)
set(PROJECT_EXTERNAL_LIBRARIES eigen)
project (${PROJECT_NAME})
#
###########
# Project #
###########
add_executable(${PROJECT_NAME} ${PROJECT_EXAMPLES})

foreach(LIBRARY ${PROJECT_EXTERNAL_LIBRARIES})
    add_subdirectory("${PROJECT_EXTERNAL_LIBRARIES_DIR}/${PROJECT_EXTERNAL_LIBRARIES}")
endforeach(LIBRARY)

target_link_libraries(${PROJECT_NAME} ${PROJECT_EXTERNAL_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include>)
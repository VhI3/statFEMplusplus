# src/CMakeLists.txt

# List of source and header files
set(PROJECT_SOURCES
    node/Node.cpp
    node/Node.hpp
    node/LocalAxis.cpp
    node/LocalAxis.hpp
    boundary/BoundaryCase.hpp
    boundary/BoundaryCase.cpp
    boundary/Constraint.hpp
    boundary/Constraint.cpp
    boundary/NodalMechLoad.hpp
    boundary/NodalMechLoad.cpp
    boundary/ElementTemp.hpp
    boundary/ElementTemp.cpp
    material/Material.hpp
    material/Material.cpp
    element/Element.hpp
)

# Define the library target
add_library(statFEMpp_lib ${PROJECT_SOURCES})

# Link the library target against Eigen3
target_link_libraries(statFEMpp_lib
    PUBLIC
    Eigen3::Eigen
)

# Specify the include directories
target_include_directories(statFEMpp_lib
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# Define the executable target for the main example
add_executable(statFEMpp_main ../examples/main.cpp)

# Link the executable target against the library
target_link_libraries(statFEMpp_main
    PRIVATE
    statFEMpp_lib
)

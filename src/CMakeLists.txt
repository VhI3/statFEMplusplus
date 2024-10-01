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
    boundary/ElementMechLoad.hpp
    boundary/ElementMechLoad.cpp
    material/Material.hpp
    material/Material.cpp
    element/Element.hpp
)

# Define the library target
add_library(statFEMpp_lib ${PROJECT_SOURCES})

# Enable precompiled headers
target_precompile_headers(statFEMpp_lib PRIVATE statFEMplusplus.hpp)

# Enable Unity build for faster compilation
set_target_properties(statFEMpp_lib PROPERTIES UNITY_BUILD ON)

# # Link the library target against Eigen3 and Matplot++
target_link_libraries(statFEMpp_lib
    PUBLIC
    Eigen3::Eigen
    Matplot++::matplot
    ${VTK_LIBRARIES}  # Add this line to link VTK
)

# Specify the include directories
target_include_directories(statFEMpp_lib
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# Define the executable target for the main example
# add_executable(statFEMpp_main ../examples/main.cpp)
add_executable(statFEMpp_main ../examples/main_exprtk_matplot.cpp)

# Link the executable target against the library
target_link_libraries(statFEMpp_main
    PRIVATE
    statFEMpp_lib
    ${VTK_LIBRARIES}  # Link the main executable against VTK
)

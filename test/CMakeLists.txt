# test/CMakeLists.txt

# Add the executable for the test
add_executable(testBoundaryCase testBoundaryCase.cpp)

# Link the BoundaryCase library and Eigen to the test executable
target_link_libraries(testBoundaryCase
    PRIVATE
    statFEMpp_lib
    Eigen3::Eigen
)

# Add a test
add_test(NAME BoundaryCaseTest COMMAND testBoundaryCase)

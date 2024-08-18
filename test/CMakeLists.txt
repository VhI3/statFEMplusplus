# test/CMakeLists.txt

# Include directories for test targets
include_directories(${CMAKE_SOURCE_DIR}/src)

include_directories(${CMAKE_SOURCE_DIR}/external/Eigen)

# Add test executable for testBoundaryCase
add_executable(testBoundaryCase
    boundary/testBoundaryCase.cpp
    ${CMAKE_SOURCE_DIR}/src/boundary/BoundaryCase.cpp
)

# Add test executable for testConstraint
add_executable(testConstraint
    boundary/testConstraint.cpp
    ${CMAKE_SOURCE_DIR}/src/boundary/BoundaryCase.cpp
    ${CMAKE_SOURCE_DIR}/src/boundary/Constraint.cpp
)


# Add test executable for testElementTemp
add_executable(testElementTemp
    boundary/testElementTemp.cpp
    ${CMAKE_SOURCE_DIR}/src/boundary/BoundaryCase.cpp
    ${CMAKE_SOURCE_DIR}/src/boundary/ElementTemp.cpp
)

# Add test executable for testElementTemp
add_executable(testNodalMechLoad
    boundary/testNodalMechLoad.cpp
    ${CMAKE_SOURCE_DIR}/src/boundary/BoundaryCase.cpp
    ${CMAKE_SOURCE_DIR}/src/boundary/NodalMechLoad.cpp
)
# Link Eigen to the testNodalMechLoad target
target_link_libraries(testNodalMechLoad Eigen3::Eigen)

# Add test executable for testDispLoad
add_executable(testDispLoad
    boundary/testDispLoad.cpp
    ${CMAKE_SOURCE_DIR}/src/boundary/BoundaryCase.cpp
    ${CMAKE_SOURCE_DIR}/src/boundary/DispLoad.cpp
)
# Link Eigen to the testDispLoad target
target_link_libraries(testDispLoad Eigen3::Eigen)



# Add testBoundaryCase to CTest
add_test(NAME testBoundaryCase COMMAND testBoundaryCase)
# set_tests_properties(testBoundaryCase PROPERTIES FAIL_REGULAR_EXPRESSION ".*")  # This forces output even on success
add_test(NAME testConstraint COMMAND testConstraint)
add_test(NAME testElementTemp COMMAND testElementTemp)
add_test(NAME testNodalMechLoad COMMAND testNodalMechLoad)
add_test(NAME testDispLoad COMMAND testDispLoad)

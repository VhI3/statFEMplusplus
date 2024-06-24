# test/CMakeLists.txt

# Include directories for test targets
include_directories(${CMAKE_SOURCE_DIR}/src)


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


# Add tests to CTest
add_test(NAME testBoundaryCase COMMAND testBoundaryCase)
add_test(NAME testConstraint COMMAND testConstraint)
add_test(NAME testElementTemp COMMAND testElementTemp)

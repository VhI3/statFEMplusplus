#include "boundary/BoundaryCase.hpp"
#include "boundary/Constraint.hpp"
#include <cassert>
#include <iostream>

void testConstraint() {
  //  Test case 1: Create a Constraint object and check its initial state
  std::string name = "Initial Constraint";
  const BoundaryCase boundaryCase("Initial BoundaryCase");
  std::array<bool, 6> constraints = {true, false, true, false, true, false};

  // Create a Constraint object
  Constraint constraint(name, boundaryCase, constraints);

  // Ensure the name is correctly set
  assert(constraint.getName() == name);
  std::cout << "Test case 1 passed: Initial name set correctly.\n";

  // Ensure the constraints are correctly set
  assert(constraint.getConstraints() == constraints);
  std::cout << "Test case 1 passed: Initial constraints set correctly.\n";

  // Ensure the BoundaryCase is correctly set
  assert(constraint.getBoundaryCase().getName() == boundaryCase.getName());
  std::cout << "Test case 1 passed: Initial BoundaryCase set correctly.\n";

  // Test case 2: Set a new name and ensure the name is correctly updated
  std::string newName = "Updated Constraint";
  constraint.setName(newName);
  // Ensure the name is correctly updated
  assert(constraint.getName() == newName);
  std::cout << "Test case 2 passed: Name updated correctly.\n";
}

int main() {
  // Run the test function
  testConstraint();
  return 0;
}

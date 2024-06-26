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

// // Function to test the Constraint class
// void testConstraint() {
//   // Test case 1: Create a Constraint object and check its initial state
//   std::string initialName = "Initial Constraint";
//   BoundaryCase boundaryCase("example");
//   std::array<bool, 6> initialFree = {true, false, true, false, true, false};
//   Constraint c(initialName, boundaryCase, initialFree);
//
//   // Ensure the name is correctly set
//   assert(c.getName() == initialName);
//   std::cout << "Test case 1 passed: Initial name set correctly.\n";
//
//   // Ensure the constraint is correctly set
//   assert(c.getConstraints() == initialFree);
//   std::cout << "Test case 1 passed: Initial constraint set correctly.\n";
//
//   // Ensure BoundaryCase is correctly set
//   assert(c.getBoundaryCase() == boundaryCase);
//   std::cout << "Test case 1 passed: Initial BoundaryCase set correctly.\n";
//
//   // Test case 2: Set a new name and ensure the name is correctly updated
//   std::string newName = "Updated Constraint";
//   c.setName(newName);
//   // Ensure the name is correctly updated
//   assert(c.getName() == newName);
//   std::cout << "Test case 2 passed: Name updated correctly.\n";
//
//   // Set a new Constraint and ensure it is correctly updated
//   std::array<bool, 6> newFree = {false, false, false, false, false, false};
//   c.setConstraints(newFree);
//   // Ensure the constraint is correctly updated
//   assert(c.getConstraints() == newFree);
//   std::cout << "Test case 2 passed: Constraint updated correctly.\n";
//
//   // Set a new BoundaryCase and ensure it is correctly updated
//   BoundaryCase newBC("Updated BoundaryCase");
//   c.setBoundaryCase(&newBC);
//   // Ensure the BoundaryCase is correctly updated
//   assert(c.getBoundaryCase() == &newBC);
//   std::cout << "Test case 2 passed: BoundaryCase updated correctly.\n";
//
//   // All tests passed
//   std::cout << "All test cases passed." << std::endl;
// }
//
int main() {
  // Run the test function
  testConstraint();
  return 0;
}

#include "boundary/BoundaryCase.hpp"
#include <cassert>
#include <iostream>

// Function to test the BoundaryCase class
void testBoundaryCase() {
  // Test case 1: Create a BoundaryCase object and check its initial state
  const std::string initialName = "Initial Boundary";
  BoundaryCase bc(initialName);

  // Ensure the name is correctly set
  assert(bc.getName() == initialName);
  std::cout << "Test case 1 passed: Initial name set correctly.\n";

  // Test case 2: Set a new name and ensure it updates correctly
  const std::string newName = "Updated Boundary";
  bc.setName(newName);

  // Ensure the name is correctly updated
  assert(bc.getName() == newName);
  std::cout << "Test case 2 passed: Name updated correctly.\n";

  std::cout << "All test cases passed.\n";
}

int main() {
  // Run the test function
  std::cout << "Running BoundaryCase test...\n";
  testBoundaryCase();
  return 0;
}

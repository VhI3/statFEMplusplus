#include "boundary/BoundaryCase.hpp"
#include "boundary/ElementTemp.hpp"
#include <cassert>
#include <iostream>

void testElementTemp() {
  // Test case 1: Create an element temperature load and check its initial state
  std::string initialName = "Initial Element";
  BoundaryCase boundaryCase("Fist BoundaryCase");
  double initialValue = 0.0;
  ElementTemp et(initialName, &boundaryCase, initialValue);

  // Ensure the name is correctly set
  assert(et.getName() == initialName);
  std::cout << "Test case 1 passed: Initial name set correctly.\n";

  // Ensure the boundaryCase is correctly set
  assert(et.getBoundaryCase() == &boundaryCase);
  std::cout << "Test case 1 passed: Initial boundaryCase set correctly.\n";

  // Ensure the value is correctly set
  assert(et.getValue() == initialValue);
  std::cout << "Test case 1 passed: Initial value set correctly.\n";
}

int main() {
  // Run the test function
  testElementTemp();
  return 0;
}

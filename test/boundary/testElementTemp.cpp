#include "boundary/BoundaryCase.hpp"
#include "boundary/ElementTemp.hpp"
#include <cassert>
#include <iostream>

void testElementTemp() {
  // Test case 1: Create an element temperature load and check its initial state
  const std::string initialName = "Initial Element";
  const BoundaryCase boundaryCase("Fist BoundaryCase");
  constexpr double initialValue = 0.0;
  const ElementTemp et(initialName, boundaryCase, initialValue);

  // Ensure the name is correctly set
  // Ensure if the getName is correctly working.
  assert(et.getName() == initialName);
  std::cout << "Test case 1 passed: Initial name set correctly.\n";

  // Ensure the boundaryCase is correctly set
  assert(et.getBoundaryCase() == boundaryCase);
  std::cout << "Test case 1 passed: Initial boundaryCase set correctly.\n";

  // Ensure the value is correctly set
  assert(et.getValue() == initialValue);
  std::cout << "Test case 1 passed: Initial value set correctly.\n";

  // Get the scale and set it.
  // Ensure the scale is correctly set
  assert(et.getLoadingScale() == 1.0);
  std::cout << "Test case 1 passed: Initial scale set correctly.\n";
}

int main() {
  // Run the test function
  std::cout << "Running ElementTemp test...\n";
  testElementTemp();
  return 0;
}

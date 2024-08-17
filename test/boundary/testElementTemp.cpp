#include "boundary/BoundaryCase.hpp"
#include "boundary/ElementTemp.hpp"
#include <cassert>
#include <iostream>

void testElementTemp() {
  // Test case 1: Create an element temperature load and check its initial state
  const std::string initialName = "Initial Element";
  const BoundaryCase boundaryCase("Fist BoundaryCase");
  constexpr double initialValue = 0.0;
  ElementTemp et(initialName, boundaryCase, initialValue);

  // Ensure the name is correctly set
  // Ensure if the getName is correctly working.
  assert(et.getName() == initialName);
  std::cout << "Test case 1 passed: Initial name set correctly.\n";

  // Ensure the boundaryCase is correctly set
  assert(et.getBoundaryCase() == boundaryCase);
  std::cout << "Test case 2 passed: Initial boundaryCase set correctly.\n";

  // Ensure the value is correctly set
  assert(et.getValue() == initialValue);
  std::cout << "Test case 3 passed: Initial value set correctly.\n";

  // Get the scale and set it.
  // Ensure the scale is correctly set
  assert(et.getLoadingScale() == 1.0);
  std::cout << "Test case 4 passed: Initial scale set correctly.\n";

  // Test case 5: Set a new name and ensure the name is correctly updated
  std::string newName = "Updated Element";
  et.setName(newName);
  // Ensure the name is correctly updated
  assert(et.getName() == newName);
  std::cout << "Test case 5 passed: Name updated correctly.\n";

  // Test case 6: Set a new boundaryCase and ensure the boundaryCase is
  // correctly updated
 const BoundaryCase newBoundaryCase("Second BoundaryCase");
  et.setBoundaryCase(newBoundaryCase);
  // Ensure the boundaryCase is correctly updated
  assert(et.getBoundaryCase() == newBoundaryCase);
  std::cout << "Test case 6 passed: BoundaryCase updated correctly.\n";

  // Test case 7: Set a new scale and ensure the scale is correctly updated
  constexpr double newScale = 2.0;
  et.setLoadingScale(newScale);
  // Ensure the scale is correctly updated
  assert(et.getLoadingScale() == newScale);
  std::cout << "Test case 7 passed: Scale updated correctly.\n";

  // Test case 8: Set a new value and ensure the value is correctly updated
  constexpr double newValue = 3.0;
  et.setValue(newValue);
  // Ensure the value is correctly updated
  assert(et.getValue() == newValue * newScale);
  std::cout << "Test case 8 passed: Value updated correctly.\n";

  std::cout << "All test cases passed.\n";
}

int main() {
  // Run the test function
  std::cout << "Running ElementTemp test...\n";
  testElementTemp();
  return 0;
}

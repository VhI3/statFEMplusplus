#include "boundary/BoundaryCase.hpp"
#include "boundary/ElementMechLoad.hpp"
#include <cassert>
#include <iostream>

void testElementMechLoad() {
  // Test case 1: Create an element mechanical load and check its initial state
  const std::string initialName = "Initial Element";
  const BoundaryCase boundaryCase("Fist BoundaryCase");
  constexpr int initialType = 0;
  constexpr int initialComponent = 0;
  constexpr double initialValue = 0.0;
  Eigen::VectorXd loadingValues(6);
  // loadingValues format is FX = 1.0, FY = 2.0, FZ = 3.0, MX = 4.0, MY = 5.0,
  // MZ = 6.0
  loadingValues << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0;
  ElementMechLoad elm(initialName, boundaryCase, initialType, initialComponent,
                      loadingValues);
  // Ensure the name is correctly set
  assert(elm.getName() == initialName);
  std::cout << "Test case 1 passed: Initial name set correctly.\n";

  // Ensure the boundaryCase is correctly set
  assert(elm.getBoundaryCase() == boundaryCase);
  std::cout << "Test case 2 passed: Initial boundaryCase set correctly.\n";

  // Ensure the type is correctly set
  assert(elm.getType() == initialType);
  std::cout << "Test case 3 passed: Initial type set correctly.\n";

  // Ensure the component is correctly set
  assert(elm.getComponent() == initialComponent);
  std::cout << "Test case 4 passed: Initial component set correctly.\n";

  // Ensure the loadingValues are correctly set
  // assert(elm.getLoadingValues() == loadingValues);
  // std::cout << "Test case 5 passed: Initial loadingValues set correctly.\n";
}

int main() {
  // Run the test function
  std::cout << "Running ElementMechLoad test...\n";
  testElementMechLoad();
  return 0;
}

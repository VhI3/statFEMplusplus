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
  constexpr Eigen::VectorXd loadingValues_;
}

int main() {
  // Run the test function
  std::cout << "Running ElementMechLoad test...\n";
  testElementMechLoad();
  return 0;
}

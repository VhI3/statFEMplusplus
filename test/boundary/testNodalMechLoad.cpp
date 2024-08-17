#include "boundary/BoundaryCase.hpp"
#include "boundary/NodalMechLoad.hpp"
#include <Eigen/Dense>
#include <cassert>
#include <iostream>

void testNodalMechLoad() {
  // Test case 1: Create a nodal mechanical load and check its initial state
  const std::string initialName = "Initial NodalMechLoad";
  const BoundaryCase boundaryCase("Fist BoundaryCase");
  // The component vector of load. It has six components; the first
  // three are forces; the last three are moments.
  Eigen::VectorXd components(6);
  components << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0;
  NodalMechLoad nml(initialName, boundaryCase, components);

  // Ensure the name is correctly set
  assert(nml.getName() == initialName);
  std::cout << "Test case 1 passed: Initial name set correctly.\n";

  // Ensure the boundaryCase is correctly set
  assert(nml.getBoundaryCase() == boundaryCase);
  std::cout << "Test case 2 passed: Initial boundaryCase set correctly.\n";

  // Ensure the components are correctly set
  assert(nml.getComponents() == components);
  std::cout << "Test case 3 passed: Initial components set correctly.\n";

  // Test case 4: Set a new name and ensure the name is correctly updated
  const std::string newName = "Updated NodalMechLoad";
  nml.setName(newName);
  // Ensure the name is correctly updated
  assert(nml.getName() == newName);
  std::cout << "Test case 4 passed: Name updated correctly.\n";

  // Test case 5: Set a new boundaryCase and ensure the boundaryCase is
  // correctly updated
  const BoundaryCase newBoundaryCase("Updated BoundaryCase");
  nml.setBoundaryCase(newBoundaryCase);
  // Ensure the boundaryCase is correctly updated
  assert(nml.getBoundaryCase() == newBoundaryCase);
  std::cout << "Test case 5 passed: BoundaryCase updated correctly.\n";

  // Test case 6: Set a new components and ensure the components are
  // correctly updated
  Eigen::VectorXd newComponents(6);
  newComponents << 7.0, 8.0, 9.0, 10.0, 11.0, 12.0;
  nml.setComponents(newComponents);
  // Ensure the components are correctly updated
  assert(nml.getComponents() == newComponents);
  std::cout << "Test case 6 passed: Components updated correctly.\n";

  std::cout << "All test cases passed.\n";
}

int main() {
  // Run the test function
  std::cout << "Running NodalMechLoad test...\n";
  testNodalMechLoad();
  return 0;
}

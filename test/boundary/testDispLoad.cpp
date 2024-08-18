// This is the test function for the class DispLoad
#include "boundary/BoundaryCase.hpp"
#include "boundary/DispLoad.hpp"
#include <cassert>
#include <iostream>

// // Function to test the DispLoad class
void testDispLoad() {
  // Test case 1: Create a DispLoad object and check its initial state
  const std::string initialName = "Initial DispLoad";
  const BoundaryCase boundaryCase("Fist BoundaryCase");
  Eigen::VectorXd components(6);
  components << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0;
  DispLoad dl(initialName, boundaryCase, components);
  // Ensure the name is correctly set
  assert(dl.getName() == initialName);
  std::cout << "Test case 1 passed: Initial name set correctly.\n";

  // Ensure the components are correctly set
  assert(dl.getComponents() == components);
  std::cout << "Test case 2 passed: Initial components set correctly.\n";

  // Ensure the coordinate system is correctly set
  const int initialCoordinateSystem = DispLoad::GLOBAL;
  assert(dl.getCoordinateSystem() == initialCoordinateSystem);
  std::cout << "Test case 3 passed: Initial coordinate system set correctly.\n";

  // Ensure the loading sclae is correctly set
  const double initialLoadingScale = 1.0;
  assert(dl.getLoadingScale() == initialLoadingScale);
  std::cout << "Test case 4 passed: Initial loading scale set correctly.\n";

  // Test case 5: Set a new name and ensure the name is correctly updated
  const std::string newName = "Updated DispLoad";
  dl.setName(newName);
  // Ensure the name is correctly updated
  assert(dl.getName() == newName);
  std::cout << "Test case 5 passed: Name updated correctly.\n";

  // Test case 6: Set a new coordinate system and ensure it is correctly
  // updated
  const int newCoordinateSystem = DispLoad::LOCAL;
  dl.setCoordinateSystem(newCoordinateSystem);
  // Ensure the coordinate system is correctly updated
  assert(dl.getCoordinateSystem() == newCoordinateSystem);
  std::cout << "Test case 6 passed: Coordinate system updated correctly.\n";

  // Test case 7: Set a new components and ensure the components are
  // correctly updated
  Eigen::VectorXd newComponents(6);
  newComponents << 7.0, 8.0, 9.0, 10.0, 11.0, 12.0;
  dl.setComponents(newComponents);
  // Ensure the components are correctly updated
  assert(dl.getComponents() == newComponents);
  std::cout << "Test case 7 passed: Components updated correctly.\n";

  // Test case 8: Set a new loading scale and ensure it is correctly
  // updated
  const double newLoadingScale = 2.0;
  dl.setLoadingScale(newLoadingScale);
  // Ensure the loading scale is correctly updated
  assert(dl.getLoadingScale() == newLoadingScale);
  std::cout << "Test case 8 passed: Loading scale updated correctly.\n";

  // Test case 9: Set a new boundary case and ensure it is correctly
  // updated
  const BoundaryCase newBoundaryCase("Second BoundaryCase");
  dl.setBoundaryCase(newBoundaryCase);
  // Ensure the boundary case is correctly updated
  assert(dl.getBoundaryCase() == newBoundaryCase);
  std::cout << "Test case 9 passed: Boundary case updated correctly.\n";

  // Test case 10: Check the default constructor
  DispLoad dl2;
  assert(dl2.getName() == "");
  std::cout << "Test case 10 passed: Default constructor works.\n";
};
//

int main() {
  // Run the test function
  std::cout << "Running DispLoad test...\n";
  testDispLoad();

  return 0;
}

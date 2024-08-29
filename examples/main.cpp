
#include "statFEMplusplus.hpp"
#include <cmath>

int main(int argc, char **argv) {

  Node<double> myNode({1., 2, 3});
  std::cout << myNode.getPosition() << std::endl;

  myNode.setPosition({1, 22, 33});
  std::cout << myNode.getPosition() << std::endl;

  // Create nodes 1 to 3
  Node<double> node1({1, 2, 3}), node2({4, 5, 6}), node3({7, 8, 9});

  return 0;
}


#include "statFEMplusplus.hpp"
#include <iostream>
int main(int argc, char **argv) {

  Node<double> myNode({1., 2, 3});
  std::cout << myNode.getPosition() << std::endl;

  myNode.setPosition({1, 22, 33});
  std::cout << myNode.getPosition() << std::endl;

  std::cout << "Test windows" << std::endl;

  return 0;
}

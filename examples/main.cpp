﻿
#include "statFEMplusplus.hpp"
#include <iostream>
int main(int argc, char **argv) {

  // The test of Lagrange 1D
  //    const auto p{2};
  //    const auto xi{-0.2f};
  //    auto rangeNaturalCoordinate =
  //    Eigen::VectorXd::LinSpaced(static_cast<Eigen::Index>(2), 0, 1);
  //    std::cout << rangeNaturalCoordinate.transpose() << std::endl;

  //    Num n(35);double
  //    std::cout << n.getNum() << std::endl;

  Node<double> myNode({1., 2, 3});
  std::cout << myNode.getPosition() << std::endl;

  myNode.setPosition({1, 22, 33});
  std::cout << myNode.getPosition() << std::endl;

  std::cout << "Test windows" << std::endl;

  return 0;
}

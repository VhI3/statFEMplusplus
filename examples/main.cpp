
// #include "matplot/matplot.h"
#include "statFEMplusplus.hpp"
#include <cmath>

int main(int argc, char **argv) {

  // using namespace matplot;

  Node<double> myNode({1., 2, 3});
  std::cout << myNode.getPosition() << std::endl;

  myNode.setPosition({1, 22, 33});
  std::cout << myNode.getPosition() << std::endl;

  std::cout << "Test windows" << std::endl;

  // Create nodes 1 to 3
  Node<double> node1({1, 2, 3}), node2({4, 5, 6}), node3({7, 8, 9});

  // std::vector<double> x = logspace(-1, 2, 20);
  // std::vector<double> y =
  //     transform(x, [](double x) { return std::pow(10., x); });
  // loglog(x, y, "s")->marker_face_color({0.f, 0.447f, 0.741f});
  // xlabel("x");
  // ylabel("10^x");
  // //
  // show();
  // //
  return 0;
}

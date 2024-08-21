
// #include "matplot/matplot.h"
#include "exprtk.hpp"
#include "statFEMplusplus.hpp"
#include <cmath>

template <typename T> void trig_function() {
  typedef exprtk::symbol_table<T> symbol_table_t;
  typedef exprtk::expression<T> expression_t;
  typedef exprtk::parser<T> parser_t;

  const std::string expression_string =
      "clamp(-1.0,sin(2 * pi * x) + cos(x / 2 * pi),+1.0)";

  T x;

  symbol_table_t symbol_table;
  symbol_table.add_variable("x", x);
  symbol_table.add_constants();

  expression_t expression;
  expression.register_symbol_table(symbol_table);

  parser_t parser;
  parser.compile(expression_string, expression);

  for (x = T(-5); x <= T(+5); x += T(0.001)) {
    const T y = expression.value();
    printf("%19.15f\t%19.15f\n", x, y);
  }
}

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
  //
  //
  //
  //
  trig_function<double>();

  return 0;
}

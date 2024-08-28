
#include "exprtk.hpp"
#include "matplot/freestanding/plot.h"
#include "matplot/matplot.h"
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

  using namespace matplot;

  Node<double> myNode({1., 2, 3});
  std::cout << myNode.getPosition() << std::endl;

  myNode.setPosition({1, 22, 33});
  std::cout << myNode.getPosition() << std::endl;

  std::cout << "Test windows" << std::endl;

  // Create nodes 1 to 3
  Node<double> node1({1, 2, 3}), node2({4, 5, 6}), node3({7, 8, 9});

  /*std::vector<double> x = linspace(0, 2 * pi);*/
  /*std::vector<double> y1 = transform(x, [](auto x) { return sin(x); });*/

  /*plot(x, y1);*/
  /*show();*/

  const std::string f_x_exp = "25x^5 - 35x^4 - 15x^3 + 40x^2 - 15x + 1";
  exprtk::symbol_table<double> symbol_table;
  exprtk::parser<double> parser;
  exprtk::expression<double> f_x;

  std::vector<double> x = linspace(0, 1.0);
  // Print all the elements of x
  for (int i = 0; i < x.size(); i++) {
    std::cout << x[i] << std::endl;
  }

  symbol_table.add_variable("x", x[0]);
  f_x.register_symbol_table(symbol_table);

  parser.compile(f_x_exp, f_x);

  /*// Store the result*/
  /*std::vector<double> y(x.size());*/
  /*for (int i = 0; i < x.size(); i++) {*/
  /*  y[i] = f_x.value();*/
  /*  symbol_table.add_variable("x", x[i]);*/
  /*}*/

  // Define y1 as a lambda function
  auto y1 = transform(x, [](auto x) { return f_x.value(); });
  // but it can not be parsed as lambda
  /*std::vector<double> y1 = transform(x, (auto x) { return f_x.value(); });*/
  /*std::cout << f_x_exp << " = " << f_x.value() << std::endl;*/
  plot(x, y1);
  show();

  /*trig_function<double>();*/

  return 0;
}

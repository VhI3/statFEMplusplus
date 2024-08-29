#include "matplot/freestanding/axes_functions.h"
#include <statFEMplusplus.hpp>

int main(int argc, char **argv) {
  using namespace matplot;

  const std::string f_x_exp = "25*x^5 - 35*x^4 - 15*x^3 + 40*x^2 - 15*x + 1";
  exprtk::symbol_table<double> symbol_table;
  exprtk::expression<double> f_x;
  exprtk::parser<double> parser;

  double x_var; // Variable to hold the value of x
  symbol_table.add_variable("x", x_var);
  f_x.register_symbol_table(symbol_table);

  if (!parser.compile(f_x_exp, f_x)) {
    std::cerr << "Error: " << parser.error() << "\n";
    return 1;
  }

  // Define the range for x
  std::vector<double> x = linspace(0.0, 1.0, 100); // 100 points between 0 and 1
  std::vector<double> y;

  // Evaluate the expression for each x
  for (double xi : x) {
    x_var = xi;               // Set the variable x to the current value
    y.push_back(f_x.value()); // Evaluate f_x at the current value of x
  }

  // Plot the result
  xlabel("x");
  ylabel("f(x)");
  xlim({0.0, 1.0});
  ylim({-0.80, 1.2});
  grid(true);
  plot(x, y);
  show();

  return 0;
}


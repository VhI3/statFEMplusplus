/*
MIT License

Copyright (c) 2023 VHI3

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "boundary/ElementMechLoad.hpp"
#include "boundary/BoundaryCase.hpp"
#include "boundary/ElementTemp.hpp"
// #include <stdexpt>

ElementMechLoad::ElementMechLoad(std::string name, BoundaryCase boundaryCase,
                                 int type, int component,
                                 const Eigen::VectorXd &loadingValues)
    : name_(std::move(name)), boundaryCase_(std::move(boundaryCase)) {
  // Set type
  if (type < 0 || type > 2)
    exceptionHandler("Illegal type for element mechanical load!");
  else
    type_ = type;

  // Set component
  if (component < 0 || component > 5)
    exceptionHandler("Illegal component for element mechanical load!");
  else
    component_ = component;

  // Set loading values
  if (checkValues(loadingValues))
    loadingValues_ = loadingValues;
}

void ElementMechLoad::exceptionHandler(const std::string &message) {
  throw std::invalid_argument(message);
}

bool ElementMechLoad::checkValues(const Eigen::VectorXd &values) {
  if (values.size() != 6)
    exceptionHandler("Illegal dimension of element mechanical load!");
  return true;
}

std::string ElementMechLoad::getName() const { return name_; }

BoundaryCase ElementMechLoad::getBoundaryCase() const { return boundaryCase_; }

int ElementMechLoad::getType() const { return type_; }

int ElementMechLoad::getComponent() const { return component_; }

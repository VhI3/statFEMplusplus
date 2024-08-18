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

#include <boundary/DispLoad.hpp>
#include <utility>

DispLoad::DispLoad(std::string name, BoundaryCase boundaryCase,
                   const Eigen::VectorXd &components)
    : name_(std::move(name)), boundaryCase_(std::move(boundaryCase)),
      components_(validateComponents(components)), scale_(1.0),
      coordinateSystem_(DispLoad::GLOBAL) {}

// This method sets the name of displacement load.
void DispLoad::setName(std::string name) { name_ = std::move(name); }

// This method sets the components of displacement load.
void DispLoad::setComponents(const Eigen::VectorXd &components) {
  components_ = validateComponents(components);
}

// This method sets the boundaryCase of displacement load.
void DispLoad::setBoundaryCase(BoundaryCase boundaryCase) {
  boundaryCase_ = std::move(boundaryCase);
}

void DispLoad::setCoordinateSystem(const int coordinateSystem) {
  if (coordinateSystem < GLOBAL || coordinateSystem > LOCAL) {
    throw std::invalid_argument("Illegal assignment for coordinate system!");
  }
  coordinateSystem_ = coordinateSystem;
}

// This method sets the loading scale of displacement load.
void DispLoad::setLoadingScale(const double scale) { scale_ = scale; }

// This method returns the name of displacement load.
const std::string &DispLoad::getName() const { return name_; }

// This method returns the boundaryCase of displacement load.
BoundaryCase DispLoad::getBoundaryCase() const { return boundaryCase_; }

// This method returns the components of displacement load.
Eigen::VectorXd DispLoad::getComponents() const { return components_ * scale_; }

// This method returns the coordinate system of displacement load.
int DispLoad::getCoordinateSystem() const { return coordinateSystem_; }

// This method returns the loading scale of displacement load.
double DispLoad::getLoadingScale() const { return scale_; }

Eigen::VectorXd
DispLoad::validateComponents(const Eigen::VectorXd &components) {
  if (components.size() != 6) {
    throw std::invalid_argument("Illegal dimension of displacement vector!");
  }
  return components;
}

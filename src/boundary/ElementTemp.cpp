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

#include "boundary/BoundaryCase.hpp"
#include <boundary/ElementTemp.hpp>
#include <utility>

ElementTemp::ElementTemp(std::string name, BoundaryCase boundaryCase,
                         const double &value)
    : name_(std::move(name)), boundaryCase_(std::move(boundaryCase)),
      scale_(1.0), value_(value) {}

void ElementTemp::setBoundaryCase(const BoundaryCase &boundaryCase) {
  boundaryCase_ = boundaryCase;
}

void ElementTemp::setName(const std::string &name) { name_ = name; }

void ElementTemp::setLoadingScale(double scale) { scale_ = scale; }

const std::string &ElementTemp::getName() const { return name_; }

const BoundaryCase &ElementTemp::getBoundaryCase() const noexcept {
  return boundaryCase_;
}

double ElementTemp::getLoadingScale() const { return scale_; }

double ElementTemp::getValue() const { return value_ * scale_; }

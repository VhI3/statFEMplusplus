/*
MIT License

Copyright (c) 2023 VHI3

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
Software, and to permit persons to whom the Software is furnished to do so,
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

#include <boundary/NodalMechLoad.hpp>

NodalMechLoad::NodalMechLoad(const std::string &name, const BoundaryCase &boundaryCase, const Eigen::VectorXd &components)
    : name_(name),
      boundaryCase_(boundaryCase),
      components_(validateComponents(components)),
      scale_(1.0),
      coordinateSystem_(NodalMechLoad::GLOBAL) {}

void NodalMechLoad::setBoundaryCase(const BoundaryCase &boundaryCase)
{
    boundaryCase_ = boundaryCase;
}

void NodalMechLoad::setCoordinateSystem(int coordinateSystem)
{
    if (coordinateSystem < GLOBAL || coordinateSystem > LOCAL)
    {
        throw std::invalid_argument("Illegal assignment for coordinate system!");
    }
    coordinateSystem_ = coordinateSystem;
}

void NodalMechLoad::setLoadingScale(double scale)
{
    scale_ = scale;
}

const std::string &NodalMechLoad::getName() const
{
    return name_;
}

const BoundaryCase &NodalMechLoad::getBoundaryCase() const
{
    return boundaryCase_;
}

Eigen::VectorXd NodalMechLoad::getComponents() const
{
    return components_ * scale_;
}

int NodalMechLoad::getCoordinateSystem() const
{
    return coordinateSystem_;
}

Eigen::VectorXd NodalMechLoad::validateComponents(const Eigen::VectorXd &components)
{
    if (components.size() != 6)
    {
        throw std::invalid_argument("Illegal dimension of load vector!");
    }
    return components;
}
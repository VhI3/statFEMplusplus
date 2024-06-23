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

#include "Constraint.hpp"

// Constructor definition
Constraint::Constraint(const std::string &name, BoundaryCase *boundaryCase, const std::array<bool, 6> &constraints)
    : name_(name), boundaryCase_(boundaryCase), free_(constraints) {}

void Constraint::setName(const std::string &name)
{
    name_ = name;
}

void Constraint::setConstraints(const std::array<bool, 6> &free)
{
    free_ = free;
}

void Constraint::setBoundaryCase(BoundaryCase *boundaryCase)
{
    boundaryCase_ = boundaryCase;
}

const std::string &Constraint::getName() const
{
    return name_;
}

const std::array<bool, 6> &Constraint::getConstraints() const
{
    return free_;
}

BoundaryCase* Constraint::getBoundaryCase() const
{
    return boundaryCase_;
}

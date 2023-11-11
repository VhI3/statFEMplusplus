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

#pragma once
#include "node/LocalAxis.h"

LocalAxis::LocalAxis(const std::string &name, int type, const Eigen::VectorXd &values) : name_(name), type_(validateType(type)), values_(validateValues(type, values)){};

static int validateType(int type)
{
    if (type < 0 || type > 1)
    {
        throw std::invalid_argument("Illegal type for local axis!");
    }
    return type;
}

static Eigen::VectorXd validateValues(int type, const Eigen::VectorXd &values)
{
    if ((type == LocalAxis::POINT && values.size() != 3) || (type == LocalAxis::LINE && values.size() != 1))
    {
        throw std::invalid_argument("Illegal dimension of local axis array!");
    }
    return values;
}

const std::string &LocalAxis::getName() const { return name_; }
int LocalAxis::getType() const { return type_; }
const Eigen::VectorXd &LocalAxis::getValues() const { return values_; }
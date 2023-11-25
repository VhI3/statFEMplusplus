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

#include <material/Material.hpp>

Material::Material(const std::string &name, double d, double dg)
{
    name_ = name;
    d_ = d;
    dg_ = dg;
}

void Material::setName(const std::string &name)
{
    name_ = name;
}

void Material::setVolumeMass(double d)
{
    if (d >= 0)
        d_ = d;
    else
        throw std::invalid_argument("Illegal assignment for mass per unit volume!");
}

void Material::setVolumeWeight(double dg)
{
    if (dg >= 0)
        dg_ = dg;
    else
        throw std::invalid_argument("Illegal assignment for weight per unit volume!");
}

const std::string &Material::getName() const
{
    return name_;
}

double Material::getVolumeMass() const
{
    return d_;
}

double Material::getVolumeWeight() const
{
    return dg_;
}
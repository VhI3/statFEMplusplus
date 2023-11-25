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
#include <vector>
#include <cmath>
#include <stdexcept>
#include <material/Material.hpp>

class Eelemet
{
public:
    /** Static variable for the coordinate system of element. */
    static const int GLOBAL = 0;
    static const int LOCAL = 1;

    /** Static variable for the principal stress/strain order. */
    static const int MINPRINCIPAL = 0;
    static const int MIDPRINCIPAL = 1;
    static const int MAXPRINCIPAL = 2;

protected:
    /** Static variable for the global dofs of element. */
    static const int UX = 0;
    static const int UY = 1;
    static const int UZ = 2;
    static const int RX = 3;
    static const int RY = 4;
    static const int RZ = 5;

    /** Static variable for the local dofs of element. */
    static const int U1 = 0;
    static const int U2 = 1;
    static const int U3 = 2;
    static const int R1 = 3;
    static const int R2 = 4;
    static const int R3 = 5;

private:
    Material material;
}
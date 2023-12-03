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
#include <Eigen/Dense>
#include <string>
#include <stdexcept>
#include <cmath>
#include <vector>

class Section
{
public:
    static const int CIRCLE = 0;
    static const int ELLIPSE = 1;
    static const int square_ = 2;
    static const int RECTANGULAR_ = 3;
    static const int ETRIANGLE_ = 4;
    static const int ITRIANGLE_ = 5;
    static const int CSEGMENT_ = 6;
    static const int CSECTOR_ = 7;
    static const int TRAPEZOID_ = 8;
    static const int POLYGON_ = 9;
    static const int HCIRCLE_ = 10;
    static const int HELLIPSE_ = 11;
    static const int TEE_ = 12;
    static const int CHANNEL_ = 13;
    static const int I_ = 14;
    static const int L_ = 15;
    static const int Z_ = 16;
    static const int TWHELLIPSE_ = 17;
    static const int TWHCIRCLE_ = 18;
    static const int TWHRECTANGLE_ = 19;
    static const int TWCHANNEL_ = 20;
    static const int C_ = 21;
    static const int HAT_ = 22;
    static const int ITWINCHANNEL_ = 23;
    static const int OTWINCHANNEL_ = 24;
    static const int EFI_ = 25;
    static const int UFI_ = 26;
    static const int TWZ_ = 27;
    static const int HCSECTOR_ = 28;
    static const int USERDEFINED_ = 29;
    static const int VARIABLE_ = 30;
    static const int THICKNESS_ = 31;
    static const int VARTHICKNESS_ = 32;
}
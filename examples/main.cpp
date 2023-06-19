// #include "statFEMpp.h"

#include <iostream>
#include "Point.h"
int main(int argc, char **argv)
{

    // We fist define the geometry of domain. For geometry we need first Points and then Lines and then Surfaces and then Volumes. 
    Point<double> p1({0, 0, 0});
    Point<double> p2({1, 0, 0});
    // std::cout << p1.getCoordinates() << std::endl;

    // p1.setCoordinates({1, 0, 0});

    // std::cout << p1.getCoordinates() << std::endl;

    return 0;
}

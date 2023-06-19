// #include "statFEMpp.h"

#include <iostream>
#include "Point.h"
int main(int argc, char **argv)
{

    // We fist define the geometry of domain. For geometry we need first Points and then Lines and then Surfaces and then Volumes. 
    auto p1 = Point<double> ({0, 0, 0});
    auto p2 = Point<double> ({1, 0, 0});


    auto l1 = line(p1, p2);


    // auto p3 = Point<double> ({2, 0, 0});
    // std::cout << p3.getCoordinates() << std::endl;

    // p1.setCoordinates({1, 0, 0});

    // std::cout << p1.getCoordinates() << std::endl;

    return 0;
}

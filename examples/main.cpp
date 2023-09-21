
#include <iostream>
#include "Node.h"
int main(int argc, char **argv)
{

    // The test of lagrange 1D
    //    const auto p{2};
    //    const auto xi{-0.2f};
    //    auto rangeNaturalCoordinate = Eigen::VectorXd::LinSpaced(static_cast<Eigen::Index>(2), 0, 1);
    //    std::cout << rangeNaturalCoordinate.transpose() << std::endl;

    //    Num n(35);
    //    std::cout << n.getNum() << std::endl;
    Node<double> myNode({1, 2, 3});
    std::cout << myNode.getCoordinates() << std::endl;

    myNode.setCoordinates({1, 22, 33});
    std::cout << myNode.getCoordinates() << std::endl;

    return 0;
}

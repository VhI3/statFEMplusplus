#include "statFEMpp.h"
using namespace std;

int main(int argc, char **argv)
{

    // The test of lagrange 1D
    int p = 2;
    auto xi = -0.2f;
    Eigen::VectorXd rangeNaturalCoordinate = Eigen::VectorXd::LinSpaced(static_cast<Eigen::Index>(2), 0, 1);
    std::cout << rangeNaturalCoordinate << std::endl;

    return 0;
}

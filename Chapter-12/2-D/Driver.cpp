#include <cmath>
#include <string>
#include "lib/BvpOde.hpp"

double rhs(double x, double y) 
{
    return -4*(1 - x*x - y*y) * exp(-(x*x + y*y));
}

int main(int argc, char* argv[])
{
    // Try new SecondOrderOde constructor:
    BoundaryConditions bc;
    int XnumNodes = 5, YnumNodes = 5;
    bc.setLhsNeumannBc(-5.0);
    bc.setRhsDirichletBc(4.0);
    SecondOrderOde ode;
    ode.setCoeffofUxx(1.0);
    ode.setCoeffofUyy(1.0);
    ode.setRhsFun(rhs);
    ode.setXmin(0.0);
    ode.setXmax(1.0);
    ode.setYmin(0.0);
    ode.setYmax(2.0);
    BvpOde bvp(&ode, &bc, XnumNodes, YnumNodes);
    bvp.setFilename("solution_poisson.dat");
    bvp.Solve();
    
    return 0;
}

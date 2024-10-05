#include <cmath>
#include <string>
#include "lib/BvpOde.hpp"

double rhs(double x, double y) {return -4*(1 - x*x - y*y) * exp(-(x*x + y*y));}
double top_boundary(double x) {return exp(-(4 + x * x)); }
double bottom_boundary(double x) {return exp(-x * x);}
double left_boundary(double y) {return exp(-y * y); }
double right_boundary(double y) {return exp(-(1 + y * y)); }

int main(int argc, char* argv[])
{
    SecondOrderOde ode;
    ode.setCoeffofUxx(1.0);
    ode.setCoeffofUyy(1.0);
    ode.setRhsFun(rhs);
    ode.setXmin(0.0);
    ode.setXmax(1.0);
    ode.setYmin(0.0);
    ode.setYmax(2.0);

    BoundaryConditions bc;
    bc.setTopBc(top_boundary);
    bc.setBottomBc(bottom_boundary);
    bc.setLeftBc(left_boundary);
    bc.setRightBc(right_boundary);

    int XnumNodes = 51, YnumNodes = 51;
    BvpOde bvp(&ode, &bc, XnumNodes, YnumNodes);
    bvp.setFilename("results/solution_poisson.dat");
    bvp.getGrid("results/x_grid.dat", "results/y_grid.dat");
    bvp.Solve();
    
    return 0;
}

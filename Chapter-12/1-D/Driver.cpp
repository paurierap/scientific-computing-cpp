#include <cmath>
#include <string>
#include "lib/BvpOde.hpp"
#include <iostream>

double prob1_rhs(double x) {return -1;}
double prob2_rhs(double x) {return 34.0*sin(x);}

int main(int argc, char* argv[])
{

    /*// Two ways of initializing odes, one as a pointer with dynamic allocation:
    SecondOrderOde *ode1 = new SecondOrderOde(1.0, 0.0, 0.0, prob1_rhs, 0.0, 1.0);
    BoundaryConditions *bc1 = new BoundaryConditions();
    int numNodes1 = 101;
    bc1->setLhsDirichletBc(0.0);
    bc1->setRhsDirichletBc(0.0);
    BvpOde bvp1(ode1, bc1, numNodes1);
    bvp1.setFilename("solution_problem1.dat");
    bvp1.Solve();
    delete ode1;
    delete bc1;
    
    // And explicitly defining the object:
    SecondOrderOde ode2(1.0, 3.0, -4.0, prob2_rhs, 0.0, M_PI);
    BoundaryConditions bc2;
    int numNodes2 = 1001;
    bc2.setLhsNeumannBc(-5.0);
    bc2.setRhsDirichletBc(4.0);
    BvpOde bvp2(&ode2, &bc2, numNodes2);
    bvp2.setFilename("solution_problem2.dat");
    bvp2.Solve();*/

    // Try new SecondOrderOde constructor:
    BoundaryConditions bc2;
    int numNodes2 = 1001;
    bc2.setLhsNeumannBc(-5.0);
    bc2.setRhsDirichletBc(4.0);
    SecondOrderOde ode2;
    ode2.setCoeffofUxx(1.0);
    ode2.setCoeffofUx(1.0);
    ode2.setCoeffofU(1.0);
    ode2.setRhsFun(prob2_rhs);
    ode2.setXmin(0.0);
    ode2.setXmax(M_PI);
    BvpOde bvp2(&ode2, &bc2, numNodes2);
    bvp2.setFilename("solution_problem2.dat");
    bvp2.Solve();
    
    return 0;
}

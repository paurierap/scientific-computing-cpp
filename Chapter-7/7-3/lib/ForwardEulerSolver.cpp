#include "ForwardEulerSolver.hpp"
#include <fstream>
#include <cassert>
#include <cmath>

double ForwardEulerSolver::RightHandSide(double t, double y)
{
    return (*p_fun)(t, y);
}

void ForwardEulerSolver::SolveEquation()
{
    std::ofstream output(filename);
    assert(output.is_open());
    double t = initialTime, y = initialValue;

    output << "t, y" << std::endl;
    output << t << ", " << y << std::endl;
    do
    {
        y += stepSize * RightHandSide(t, y);
        t += stepSize;
        output << t << ", " << y << std::endl;
    } while (fabs(t - finalTime) > 1e-8);

    output.close();
}
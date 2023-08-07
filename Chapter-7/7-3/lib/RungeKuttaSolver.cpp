#include "../include/RungeKuttaSolver.h"
#include <fstream>
#include <cassert>
#include <cmath>

double RungeKuttaSolver::RightHandSide(double t, double y)
{
    return 1 + t;
}

void RungeKuttaSolver::SolveEquation()
{
    std::ofstream output("RK_" + std::to_string((int)(finalTime / stepSize)) + ".csv");
    assert(output.is_open());
    double t = initialTime, y = initialValue;
    double k1, k2, k3, k4;

    output << t << ", " << y << std::endl;
    do
    {
        k1 = stepSize * RightHandSide(t, y);
        k2 = stepSize * RightHandSide(t + 0.5 * stepSize, y + 0.5 * k1);
        k3 = stepSize * RightHandSide(t + 0.5 * stepSize, y + 0.5 * k2);
        k4 = stepSize * RightHandSide(t + stepSize, y + k3);
        y += 1. / 6 * (k1 + 2 * k2 + 2 * k3 + k4);

        t += stepSize;
        output << t << ", " << y << std::endl;
    } while (fabs(t - finalTime) > 1e-8);

    output.close();
}
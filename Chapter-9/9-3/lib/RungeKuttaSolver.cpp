#include "RungeKuttaSolver.hpp"
#include "StepSizeException.hpp"
#include <cassert>
#include <cmath>
#include <exception>
#include <fstream>

double RungeKuttaSolver::RightHandSide(double t, double y)
{
    return (*p_fun)(t, y);
}

void RungeKuttaSolver::SolveEquation()
{
    std::ofstream output("solution.csv");
    double t = initialTime, y = initialValue;

    assert(output.is_open());

    output << "t, y" << std::endl;
    output << t << ", " << y << std::endl;
    do
    {
        double k1, k2, k3, k4;

        k1 = stepSize * RightHandSide(t, y);
        k2 = stepSize * RightHandSide(t + 0.5 * stepSize, y + 0.5 * k1);
        k3 = stepSize * RightHandSide(t + 0.5 * stepSize, y + 0.5 * k2);
        k4 = stepSize * RightHandSide(t + stepSize, y + k3);
        y += 1. / 6 * (k1 + 2 * k2 + 2 * k3 + k4);

        // - Fix -
        // Error type 1: y is 1e-6 above or below 1 or 0
        double eps = 1e-6;
        if (y < 0 && y > -eps)
        {
            y = 0.;
        }
        else if (y > 1 && y < 1 + eps)
        {
            y = 1.;
        }

        // - Exception -
        // Error type 2: y is out of range
        else if (y < -eps || y > 1 + eps)
        {
            output.close();
            throw StepSizeException();
        }

        t += stepSize;
        output << t << ", " << y << std::endl;
    } while (fabs(t - finalTime) > 1e-8);

    output.close();
}
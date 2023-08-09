// Use only Runge Kutta solver
#include "../lib/RungeKuttaSolver.hpp"
#include "../lib/StepSizeException.hpp"
#include <cassert>
#include <exception>
#include <iostream>

// The code should be easily extensible to a forward Euler solver.

double f(double t, double y)
{
    return -100 * y;
}

int main()
{
    double t0 = 0, t1 = 100, y0 = 0.8, h = 1;
    RungeKuttaSolver RKSol;
    bool repeat = true;

    while (repeat)
    {
        try
        {
            // - Assertion -
            // Error type 3: h is below a threshold value.
            assert(h > 0.01);

            RKSol.SetStepSize(h);
            RKSol.SetTimeInterval(t0, t1);
            RKSol.SetInitialValue(y0);
            RKSol.p_fun = &f;
            RKSol.SolveEquation();
            repeat = false;
        }
        catch (std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
            h *= 0.5;
        }
    }

    std::cout << "Solver has finished. Calculation successful, with h = " << h << std::endl;

    return 0;
}
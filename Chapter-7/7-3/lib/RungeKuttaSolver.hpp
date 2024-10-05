#ifndef RUNGEKUTTAH
#define RUNGEKUTTAH

#include "AbstractOdeSolver.hpp"

class RungeKuttaSolver : public AbstractOdeSolver
{
public:
    double (*p_fun)(double, double);
    double RightHandSide(double, double);
    void SolveEquation();
};

#endif
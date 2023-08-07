#ifndef RUNGEKUTTAH
#define RUNGEKUTTAH

#include "AbstractOdeSolver.h"

class RungeKuttaSolver : public AbstractOdeSolver
{
public:
    double (*p_fun)(double, double);
    double RightHandSide(double, double);
    void SolveEquation();
};

#endif
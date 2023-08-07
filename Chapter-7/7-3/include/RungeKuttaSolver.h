#ifndef RUNGEKUTTAH
#define RUNGEKUTTAH

#include "AbstractOdeSolver.h"

class RungeKuttaSolver : public AbstractOdeSolver
{
public:
    double RightHandSide(double, double);
    void SolveEquation();
};

#endif
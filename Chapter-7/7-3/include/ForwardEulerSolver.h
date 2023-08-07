#ifndef FORWARDEULERH
#define FORWARDEULERH

#include "AbstractOdeSolver.h"

class ForwardEulerSolver : public AbstractOdeSolver
{
public:
    double (*p_fun)(double, double);
    double RightHandSide(double, double);
    void SolveEquation();
};

#endif
#ifndef FORWARDEULERH
#define FORWARDEULERH

#include "AbstractOdeSolver.h"

class ForwardEulerSolver : public AbstractOdeSolver
{
public:
    double RightHandSide(double, double);
    void SolveEquation();
};

#endif
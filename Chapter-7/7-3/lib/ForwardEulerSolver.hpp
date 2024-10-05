#ifndef FORWARDEULERH
#define FORWARDEULERH

#include "AbstractOdeSolver.hpp"

class ForwardEulerSolver : public AbstractOdeSolver
{
public:
    double (*p_fun)(double, double);
    double RightHandSide(double, double);
    void SolveEquation();
};

#endif
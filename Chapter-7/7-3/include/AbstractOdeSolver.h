#ifndef ABSTRACTODESOLVERH
#define ABSTRACTODESOLVERH

class AbstractOdeSolver
{
protected:
    double stepSize;
    double initialTime;
    double finalTime;
    double initialValue;

public:
    void SetStepSize(double);
    void SetTimeInterval(double, double);
    void SetInitialValue(double);
    virtual double RightHandSide(double, double) = 0;
    virtual void SolveEquation() = 0;
};

#endif
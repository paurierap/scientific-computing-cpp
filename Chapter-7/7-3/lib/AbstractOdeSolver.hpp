#ifndef ABSTRACTODESOLVERH
#define ABSTRACTODESOLVERH

#include <string>

class AbstractOdeSolver
{
protected:
    double stepSize;
    double initialTime;
    double finalTime;
    double initialValue;
    std::string filename;

public:
    void SetStepSize(double);
    void SetTimeInterval(double, double);
    void SetInitialValue(double);
    void SetFilename(std::string);
    virtual double RightHandSide(double, double) = 0;
    virtual void SolveEquation() = 0;
};

#endif
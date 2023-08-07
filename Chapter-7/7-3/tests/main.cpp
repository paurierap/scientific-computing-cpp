#include "../include/ForwardEulerSolver.h"
#include "../include/RungeKuttaSolver.h"
/*double f(double t, double y)
{
    return 1 + t;
}
*/
int main()
{
    double t0 = 0, t1 = 1, y0 = 2;
    double h[4] = {0.1, 0.05, 0.025, 0.0125};
    ForwardEulerSolver EulerSol[4];
    RungeKuttaSolver RKSol[4];

    for (int i = 0; i < 4; ++i)
    {
        EulerSol[i].SetStepSize(h[i]);
        EulerSol[i].SetTimeInterval(t0, t1);
        EulerSol[i].SetInitialValue(y0);
        // RKSol[i].RightHandSide();
        EulerSol[i].SolveEquation();

        RKSol[i].SetStepSize(h[i]);
        RKSol[i].SetTimeInterval(t0, t1);
        RKSol[i].SetInitialValue(y0);
        // RKSol[i].RightHandSide();
        RKSol[i].SolveEquation();
    }

    return 0;
}
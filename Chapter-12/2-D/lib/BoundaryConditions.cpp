#include "BoundaryConditions.hpp"
#include <cassert>

BoundaryConditions::BoundaryConditions()
{
    isTopBCset = isBottomBCset = isLeftBCset = isRightBCset = false;
}

void BoundaryConditions::setTopBc(double (*TopBoundary)(double x))
{
    mpTopBoundary = TopBoundary;
    isTopBCset = true;
}

void BoundaryConditions::setBottomBc(double (*BottomBoundary)(double x))
{
    mpBottomBoundary = BottomBoundary;
    isBottomBCset = true;
}

void BoundaryConditions::setLeftBc(double (*LeftBoundary)(double y))
{
    mpLeftBoundary = LeftBoundary;
    isLeftBCset = true;
}

void BoundaryConditions::setRightBc(double (*RightBoundary)(double y))
{
    mpRightBoundary = RightBoundary;
    isRightBCset = true;
}
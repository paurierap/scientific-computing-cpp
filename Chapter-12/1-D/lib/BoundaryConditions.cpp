#include "BoundaryConditions.hpp"
#include <cassert>

BoundaryConditions::BoundaryConditions()
{
    mLhsBcisDirichlet = false;
    mRhsBcisDirichlet = false;
    mLhsBcisNeumann = false;
    mRhsBcisNeumann = false;
}

void BoundaryConditions::setLhsDirichletBc(double lhsValue)
{
    assert(!mLhsBcisNeumann);
    mLhsBcisDirichlet = true;
    mLhsBcValue = lhsValue;
}

void BoundaryConditions::setRhsDirichletBc(double rhsValue)
{
    assert(!mRhsBcisNeumann);
    mRhsBcisDirichlet = true;
    mRhsBcValue = rhsValue;
}

void BoundaryConditions::setLhsNeumannBc(double lhsDerivValue)
{
    assert(!mLhsBcisDirichlet);
    mLhsBcisNeumann = true;
    mLhsBcValue = lhsDerivValue;
}

void BoundaryConditions::setRhsNeumannBc(double rhsDerivValue)
{
    assert(!mRhsBcisDirichlet);
    mRhsBcisNeumann = true;
    mRhsBcValue = rhsDerivValue;
}
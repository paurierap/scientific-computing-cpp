#include "PosDefSymmLinearSystem.hpp"
#include <iostream>

PosDefSymmLinearSystem::PosDefSymmLinearSystem(const Matrix &A, const Vector &b) : LinearSystem(A, b)
{
}

/* PosDefSymmLinearSystem::~PosDefSymmLinearSystem()
{
    delete mpA;
    delete mpb;
}*/

Vector PosDefSymmLinearSystem::solve()
{
    Matrix A = *mpA;
    Vector b = *mpb;
    Vector x(mSize);

    // Check if matrix is symmetric:
    for (int i = 0; i < mSize - 1; ++i)
    {
        for (int j = i + 1; j < mSize; ++j)
        {
            assert(A(i + 1, j + 1) == A(j + 1, i + 1));
        }
    }

    return x;
}
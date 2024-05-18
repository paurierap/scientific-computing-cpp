#include "LinearSystem.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>
#include <cmath>

LinearSystem::LinearSystem(const LinearSystem &other_system)
{
}

LinearSystem::LinearSystem(const Matrix &A, const Vector &b) : mSize(b.getSize())
{
    assert(A.getRows() == mSize && A.getCols() == mSize);

    mpA = new Matrix(A);
    mpb = new Vector(b);
}

LinearSystem::~LinearSystem()
{
    delete mpA;
    delete mpb;
}

Vector LinearSystem::solve()
{
    Vector sol(mSize);
    Vector M(mSize);
    Vector b = *mpb;
    Matrix A = *mpA;

    for (int j = 0; j < mSize - 1; j++)
    {
        // See if pivoting is necessary
        double max = 0.0;
        int row = -1;

        for (int i = j; i < mSize; i++)
        {
            if (fabs(A(i + 1, j + 1)) > max)
            {
                row = i;
                max = fabs(A(i + 1, j + 1));
            }
        }
        assert(row >= 0);

        // Pivot if necessary
        if (row != j)
        {
            // Swap matrix rows k+1 with row+1
            for (int k = j; k < mSize; k++)
            {
                double temp = A(j + 1, k + 1);
                A(j + 1, k + 1) = A(row + 1, k + 1);
                A(row + 1, k + 1) = temp;
            }

            // Swap vector entries k+1 with row+1
            double temp = b(j + 1);
            b(j + 1) = b(row + 1);
            b(row + 1) = temp;
        }

        for (int i = j + 1; i < mSize; i++)
        {
            double scale = A(i + 1, j + 1) / A(j + 1, j + 1);
            b(i + 1) -= scale * b(j + 1);

            for (int k = j + 1; k < mSize; k++)
            {
                A(i + 1, k + 1) -= scale * A(j + 1, k + 1);
            }
            A(i + 1, j + 1) = 0;
        }
    }

    // Backward solution of the triangular matrix:
    for (int i = mSize - 1; i >= 0; --i)
    {
        double sum = 0;
        for (int j = i + 1; j < mSize; j++)
        {
            sum += A(i + 1, j + 1) * sol(j + 1);
        }
        sol(i + 1) = 1 / A(i + 1, i + 1) * (b(i + 1) - sum);
    }

    return sol;
}
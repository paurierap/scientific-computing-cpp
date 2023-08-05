#include "../include/matrix.h"
#include <cassert>

// 1:
void Matrix::allocate()
{
    size = 2;
    mat_els = new double *[size];

    for (int i = 0; i < size; ++i)
    {
        mat_els[i] = new double[size];
    }
}

Matrix::Matrix()
{
    allocate();
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            mat_els[i][j] = 0;
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < size; ++i)
    {
        delete[] mat_els[i];
    }

    delete[] mat_els;
}

// 2:
Matrix::Matrix(const Matrix &A)
{
    size = A.size;
    allocate();
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            mat_els[i][j] = A.mat_els[i][j];
        }
    }
}

// 3:
Matrix::Matrix(double a, double b, double c, double d)
{
    size = 2;
    allocate();
    mat_els[0][0] = a;
    mat_els[0][1] = b;
    mat_els[1][0] = c;
    mat_els[1][1] = d;
}

// 4:
double Matrix::det() const
{
    return mat_els[0][0] * mat_els[1][1] - mat_els[1][0] * mat_els[0][1];
}

// 5:
Matrix Matrix::inv() const
{
    assert(det() != 0);
    Matrix A(mat_els[1][1], -mat_els[0][1], -mat_els[1][0], mat_els[0][0]);

    return A * (1. / det());
}

// 6:
Matrix &Matrix::operator=(const Matrix &A)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            mat_els[i][j] = A.mat_els[i][j];
        }
    }

    return *this;
}

// 7:
Matrix Matrix::operator-() const
{
    Matrix A;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            A.mat_els[i][j] = -1. * mat_els[i][j];
        }
    }

    return A;
}

// 8:
Matrix Matrix::operator+(const Matrix &A) const
{
    Matrix B;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            B.mat_els[i][j] = mat_els[i][j] + A.mat_els[i][j];
        }
    }

    return B;
}

Matrix Matrix::operator-(const Matrix &A) const
{
    Matrix B;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            B.mat_els[i][j] = mat_els[i][j] - A.mat_els[i][j];
        }
    }

    return B;
}

// 9:
Matrix Matrix::operator*(const double &x) const
{
    Matrix B;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            B.mat_els[i][j] = mat_els[i][j] * x;
        }
    }

    return B;
}

// Print Matrix
std::ostream &operator<<(std::ostream &out, const Matrix &A)
{
    for (int i = 0; i < A.size; ++i)
    {
        for (int j = 0; j < A.size; ++j)
        {
            out << A.mat_els[i][j] << " ";
        }

        out << std::endl;
    }

    return out;
}
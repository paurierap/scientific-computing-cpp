#include "Matrix.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

/* Constructor square matrix */

Matrix::Matrix(int size) : mRows(size), mCols(size)
{
    assert(mRows > 0 && mCols > 0);

    mData = new double *[mRows];
    for (int i = 0; i < mRows; ++i)
    {
        mData[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j)
        {
            mData[i][j] = 0.;
        }
    }
}

/* Constructor general matrix */

Matrix::Matrix(int rows, int cols) : mRows(rows), mCols(cols)
{
    assert(mRows > 0 && mCols > 0);

    mData = new double *[mRows];
    for (int i = 0; i < mRows; ++i)
    {
        mData[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j)
        {
            mData[i][j] = 0.;
        }
    }
}

/* Copy constructor */

Matrix::Matrix(const Matrix &M) : mRows(M.mRows), mCols(M.mCols)
{
    mData = new double *[mRows];
    for (int i = 0; i < mRows; ++i)
    {
        mData[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j)
        {
            mData[i][j] = M.mData[i][j];
        }
    }
}

/* Destructor*/

Matrix::~Matrix()
{
    for (int i = 0; i < mRows; ++i)
    {
        delete[] mData[i];
    }

    delete[] mData;
}

/* Get number of rows. */

int Matrix::getRows() const
{
    return mRows;
}

/* Get number of columns. */

int Matrix::getCols() const
{
    return mCols;
}

/*An overloaded round bracket operator with one-based indexing for accessing the entries of the matrix so that, provided i and j are valid indices for the matrix, A(i,j) may be used to access mData[i-1][j-1].*/

double &Matrix::operator()(int i, int j)
{
    assert(i > 0 && i <= mRows);
    assert(j > 0 && j <= mCols);

    return mData[i - 1][j - 1];
}

/* Copy assignment operator. */

Matrix &Matrix::operator=(const Matrix &M)
{
    assert(mRows == M.mRows && mCols == M.mCols);

    if (this != &M)
    {
        for (int i = 0; i < mRows; ++i)
        {
            for (int j = 0; j < mCols; ++j)
            {
                mData[i][j] = M.mData[i][j];
            }
        }
    }

    return *this;
}

Matrix &Matrix::operator+=(const Matrix &M)
{
    assert(mRows == M.mRows && mCols == M.mCols);

    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            mData[i][j] += M.mData[i][j];
        }
    }

    return *this;
}

Matrix &Matrix::operator-=(const Matrix &M)
{
    assert(mRows == M.mRows && mCols == M.mCols);

    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            mData[i][j] -= M.mData[i][j];
        }
    }

    return *this;
}

Matrix &Matrix::operator*=(const Matrix &M)
{
    assert(mCols == M.mRows);

    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < M.mCols; ++j)
        {
            for (int k = 0; k < mCols; ++k)
            {
                mData[i][j] += mData[i][k] * M.mData[k][j];
            }
        }
    }

    return *this;
}

Matrix &Matrix::operator+=(double scalar)
{
    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            mData[i][j] += scalar;
        }
    }

    return *this;
}

Matrix &Matrix::operator-=(double scalar)
{
    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            mData[i][j] -= scalar;
        }
    }

    return *this;
}

Matrix &Matrix::operator*=(double scalar)
{
    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            mData[i][j] += scalar;
        }
    }

    return *this;
}

/* Unary negative operator. */

Matrix Matrix::operator-() const
{
    Matrix M(mRows, mCols);

    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            M.mData[i][j] = -mData[i][j];
        }
    }

    return M;
}

/* Addition of matrices.

Matrix Matrix::operator+(const Matrix &M) const
{
    assert(mRows == M.mRows && mCols == M.mCols);

    Matrix A(mRows, mCols);

    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            A(i + 1, j + 1) = mData[i][j] + M.mData[i][j];
        }
    }

    return A;
} */

/* Subtraction of matrices. */

/*Matrix Matrix::operator-(const Matrix &M) const
{
    assert(mRows == M.mRows && mCols == M.mCols);

    Matrix A(mRows, mCols);

    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            A(i + 1, j + 1) = mData[i][j] - M.mData[i][j];
        }
    }

    return A;
} */

/* Multiplication of matrices. */

/*Matrix Matrix::operator*(const Matrix &M) const
{
    assert(mCols == M.mRows);

    Matrix A(mRows, M.mCols);

    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < M.mCols; ++j)
        {
            for (int k = 0; k < mCols; ++k)
            {
                A(i + 1, j + 1) += mData[i][k] * M.mData[k][j];
            }
        }
    }

    return A;
} */

Matrix operator+(const Matrix &A, const Matrix &B)
{
    return Matrix(A) += B;
}

Matrix operator-(const Matrix &A, const Matrix &B)
{
    return Matrix(A) -= B;
}

Matrix operator*(const Matrix &A, const Matrix &B)
{
    return Matrix(A) *= B;
}

Matrix operator+(const Matrix &A, double scalar)
{
    return Matrix(A) += scalar;
}

Matrix operator-(const Matrix &A, double scalar)
{
    return Matrix(A) -= scalar;
}

Matrix operator*(const Matrix &A, double scalar)
{
    return Matrix(A) *= scalar;
}

Matrix operator+(double scalar, const Matrix &A)
{
    return Matrix(A) += scalar;
}

Matrix operator-(double scalar, const Matrix &A)
{
    return Matrix(A) -= scalar;
}

Matrix operator*(double scalar, const Matrix &A)
{
    return Matrix(A) *= scalar;
}

/* Matrix-vector multiplication. */

Vector Matrix::operator*(const Vector &v) const
{
    assert(mCols == v.mSize);

    Vector u(mRows);

    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            u[i] += mData[i][j] * v.mData[j];
        }
    }

    return u;
}

/* Addition by a scalar. */

/*Matrix Matrix::operator+(double scalar) const
{
    Matrix A(mRows, mCols);

    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            A.mData[i][j] = mData[i][j] + scalar;
        }
    }

    return A;
}*/

/* Subtraction by a scalar. */

/*Matrix Matrix::operator-(double scalar) const
{
    Matrix A(mRows, mCols);

    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            A.mData[i][j] = mData[i][j] - scalar;
        }
    }

    return A;
}*/

/* Multiplication by a scalar. */

/*Matrix Matrix::operator*(double scalar) const
{
    Matrix A(mRows, mCols);

    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            A.mData[i][j] = scalar * mData[i][j];
        }
    }

    return A;
}*/

/* Compute determinant of square matrix. */

double Matrix::det() const
{
    assert(mRows == mCols);

    if (mRows == 1)
    {
        return mData[0][0];
    }

    double detsum = 0.;

    for (int k = 0; k < mRows; ++k)
    {
        Matrix A(mRows - 1, mCols - 1);

        for (int i = 1; i < mRows; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                A(i, j + 1) = mData[i][j];
            }
            for (int j = k + 1; j < mCols; ++j)
            {
                A(i, j) = mData[i][j];
            }
        }

        detsum += pow(-1, k) * mData[0][k] * A.det();
    }

    return detsum;
}

std::ostream &operator<<(std::ostream &out, const Matrix &M)
{
    for (int i = 0; M.mRows; ++i)
    {
        for (int j = 0; M.mCols; ++j)
        {
            out << " " << M.mData[i][j];
        }

        out << std::endl;
    }
    return out;
}
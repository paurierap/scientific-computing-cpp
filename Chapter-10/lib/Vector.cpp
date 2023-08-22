#include "Vector.hpp"
#include <cmath>
#include <iostream>
#include <cassert>

Vector::Vector(int size) : mSize(size)
{
    assert(mSize > 0);
    mData = new double[mSize];
    for (int i = 0; i < mSize; ++i)
    {
        mData[i] = 0.;
    }
}

Vector::Vector(const Vector &v) : mSize(v.mSize)
{
    mData = new double[mSize];
    for (int i = 0; i < mSize; ++i)
    {
        mData[i] = v.mData[i];
    }
}

Vector::~Vector()
{
    delete[] mData;
}

int Vector::getSize() const
{
    return mSize;
}

double &Vector::operator[](int i)
{
    assert(i >= 0);
    assert(i < mSize);
    return mData[i];
}

double Vector::read(int i) const
{
    assert(i >= 0);
    assert(i < mSize);
    return mData[i];
}

// Matlab notation, going from 1 to mSize
double &Vector::operator()(int i)
{
    /*assert(i > 0);
    assert(i <= mSize);
    return mData[i - 1];*/
    return (*this)[i - 1];
}

Vector &Vector::operator=(const Vector &v)
{
    assert(mSize == v.mSize);
    for (int i = 0; i < mSize; ++i)
    {
        mData[i] = v.mData[i];
    }
    return *this;
}

Vector &Vector::operator+=(const Vector &v)
{
    assert(mSize == v.mSize);
    for (int i = 0; i < mSize; ++i)
    {
        mData[i] += v.mData[i];
    }
    return *this;
}

Vector &Vector::operator-=(const Vector &v)
{
    assert(mSize == v.mSize);
    for (int i = 0; i < mSize; ++i)
    {
        mData[i] -= v.mData[i];
    }
    return *this;
}

const Vector Vector::operator+() const
{
    Vector v(mSize);
    for (int i = 0; i < mSize; ++i)
    {
        v[i] = mData[i];
    }
    return v;
}

const Vector Vector::operator-() const
{
    Vector v(mSize);
    for (int i = 0; i < mSize; ++i)
    {
        v[i] = -mData[i];
    }
    return v;
}

Vector operator+(const Vector &lhs, const Vector &rhs)
{
    return Vector(lhs) += rhs;
}

Vector operator-(const Vector &lhs, const Vector &rhs)
{
    return Vector(lhs) -= rhs;
}

/*Vector Vector::operator+(const Vector &v) const
{
    assert(mSize == v.mSize);
    Vector w(mSize);
    for (int i = 0; i < mSize; ++i)
    {
        w[i] = mData[i] + v.mData[i];
    }
    return w;
}

const Vector Vector::operator-(const Vector &v) const
{
    assert(mSize == v.mSize);
    Vector w(mSize);
    for (int i = 0; i < mSize; ++i)
    {
        w[i] = mData[i] - v.mData[i];
    }
    return w;
}*/

Vector operator*(const Vector &v, double scalar)
{
    Vector u(v.mSize);
    for (int i = 0; i < v.mSize; ++i)
    {
        u[i] = scalar * v.mData[i];
    }
    return u;
}

Vector operator*(double scalar, const Vector &v)
{
    return v * scalar;
}

const Vector Vector::operator*(const Matrix &M) const
{
    assert(mSize == M.mCols);

    Vector u(M.mCols);

    for (int i = 0; i < M.mCols; ++i)
    {
        for (int j = 0; j < mSize; ++j)
        {
            u[i] += mData[j] * M.mData[j][i];
        }
    }

    return u;
}

/*const Vector Vector::operator*(double a) const
{
    Vector v(mSize);
    for (int i = 0; i < mSize; ++i)
    {
        v[i] = a * mData[i];
    }
    return v;
}*/

double Vector::norm(int p) const
{
    double sum = 0.;
    for (int i = 0; i < mSize; ++i)
    {
        sum += pow(fabs(mData[i]), p);
    }
    sum = pow(sum, 1 / ((double)(p)));
    return sum;
}

int length(const Vector &v)
{
    return v.mSize;
}

// Overloading the output stream insertion << operator
std::ostream &operator<<(std::ostream &output, const Vector &v)
{
    for (int i = 0; i < v.getSize(); i++)
    {
        output << v.read(i) << std::endl;
    }
    return output;
}
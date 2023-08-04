// Implementation of complex numbers

#include "../include/complex.h"
#include <cmath>

// Default constructor
Complex::Complex()
{
    mRe = 0;
    mIm = 0;
}

// Constructor
Complex::Complex(double real, double imag)
{
    mRe = real;
    mIm = imag;
}

// Compute modulus
double Complex::mod() const
{
    return sqrt(mRe * mRe + mIm * mIm);
}

// Compute argument
double Complex::arg() const
{
    return atan2(mIm, mRe);
}

// Compute n-th power
Complex Complex::pow_n(double n) const
{
    double mMod = mod();
    double mArg = arg();
    Complex z(pow(mMod, n) * cos(n * mArg), pow(mMod, n) * sin(n * mArg));
    return z;
}

// Overload assignment (=) operator
Complex &Complex::operator=(const Complex &z)
{
    mRe = z.mRe;
    mIm = z.mIm;
    return *this;
}

// Overload negative operator
Complex Complex::operator-() const
{
    Complex z(-mRe, -mIm);
    return z;
}

// Overload addition operator
Complex Complex::operator+(const Complex &z) const
{
    Complex w(mRe + z.mRe, mIm + z.mIm);
    return w;
}

// Overload subtraction operator
Complex Complex::operator-(const Complex &z) const
{
    Complex w(mRe - z.mRe, mIm - z.mIm);
    return w;
}

// Overload cout
std::ostream &operator<<(std::ostream &out, const Complex &z)
{
    if (z.mIm >= 0)
    {
        out << z.mRe << "+ i" << z.mIm;
        return out;
    }

    out << z.mRe << "- i" << -z.mIm;
    return out;
}
// Implementation of complex numbers

#include "complex.hpp"
#include <cmath>

// Default constructor
Complex::Complex() : mRe(0), mIm(0) {}

// Constructor with default behaviour for real numbers
Complex::Complex(double real, double imag) : mRe(real), mIm(imag) {}

// Copy constructor
Complex::Complex(const Complex &z) : mRe(z.mRe), mIm(z.mIm) {}

// Get real part
double Complex::getRe() const
{
    return mRe;
}

// Get imaginary part
double Complex::getIm() const
{
    return mIm;
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

Complex Complex::conjugate() const
{
    Complex w(mRe, -mIm);
    return w;
}

void Complex::set2conj()
{
    mIm = -mIm;
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
        out << z.mRe << "+" << z.mIm << "i";
        return out;
    }

    out << z.mRe << "-" << -z.mIm << "i";
    return out;
}

double real(const Complex &z)
{
    return z.mRe;
}

double imag(const Complex &z)
{
    return z.mIm;
}
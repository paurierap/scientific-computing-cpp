#include "Complex.hpp"
#include <cmath>

// Default constructor
Complex::Complex() : mMod(0), mArg(0) {}

// Constructor with default behaviour for real numbers
Complex::Complex(double mod, double arg) : mArg(arg)
{
    assert(mod >= 0);
    mMod = mod;
}

// Copy constructor
Complex::Complex(const Complex &z) : mMod(z.mMod), mArg(z.mArg) {}

// Get real part
double Complex::getRe() const
{
    return mMod * cos(mArg);
}

// Get imaginary part
double Complex::getIm() const
{
    return mMod * sin(mArg);
}

// Compute modulus
double Complex::mod() const
{
    return mMod;
}

// Compute argument
double Complex::arg() const
{
    return mArg;
}

bool Complex::islowerunity() const
{
    return mMod < 1;
}

// Compute n-th power
Complex Complex::pow_n(double n) const
{
    Complex z(pow(mMod, n) * cos(n * mArg), pow(mMod, n) * sin(n * mArg));

    return z;
}

Complex Complex::conjugate() const
{
    Complex w(mMod, -mArg);
    return w;
}

void Complex::set2conj()
{
    mArg = -mArg;
}

// Overload assignment (=) operator
Complex &Complex::operator=(const Complex &z)
{
    mMod = z.mMod;
    mArg = z.mArg;
    return *this;
}

// Overload negative operator
Complex Complex::operator-() const
{
    Complex z(mMod, mArg + M_PI_2);
    return z;
}

// Overload addition operator
Complex Complex::operator+(const Complex &z) const
{

    double mod = sqrt(pow((z.mMod * cos(z.mArg) + mMod * cos(mArg)), 2) + pow((z.mMod * sin(z.mArg) + mMod * sin(mArg)), 2));
    double arg = atan2((z.mMod * sin(z.mArg) + mMod * sin(mArg)), (z.mMod * cos(z.mArg) + mMod * cos(mArg)));

    Complex w(mod, arg);
    return w;
}

// Overload subtraction operator
Complex Complex::operator-(const Complex &z) const
{
    double mod = sqrt(pow((-z.mMod * cos(z.mArg) + mMod * cos(mArg)), 2) + pow((-z.mMod * sin(z.mArg) + mMod * sin(mArg)), 2));
    double arg = atan2((-z.mMod * sin(z.mArg) + mMod * sin(mArg)), (-z.mMod * cos(z.mArg) + mMod * cos(mArg)));

    Complex w(mod, arg);
    return w;
}

// Overload cout
std::ostream &operator<<(std::ostream &out, const Complex &z)
{
    if (z.mArg >= 0 && z.mArg <= M_PI)
    {
        out << z.mMod * cos(z.mArg) << "+" << z.mMod * sin(z.mArg) << "i";
        return out;
    }

    out << z.mMod * cos(z.mArg) << "-" << -z.mMod * sin(z.mArg) << "i";
    return out;
}

double real(const Complex &z)
{
    return z.mMod * cos(z.mArg);
}

double imag(const Complex &z)
{
    return z.mMod * sin(z.mArg);
}
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex
{
    friend class ComplexTestSuite;

private:
    double mMod, mArg;

public:
    Complex();
    Complex(double, double = 0);
    Complex(const Complex &);
    double getRe() const;
    double getIm() const;
    double mod() const;
    double arg() const;
    bool islowerunity() const;
    Complex pow_n(double) const;
    Complex conjugate() const;
    void set2conj();
    Complex &operator=(const Complex &);
    Complex operator-() const;
    Complex operator+(const Complex &) const;
    Complex operator-(const Complex &) const;
    friend std::ostream &operator<<(std::ostream &, const Complex &);
    friend double real(const Complex &);
    friend double imag(const Complex &);
};

#endif
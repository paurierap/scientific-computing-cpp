// Interface of complex numbers

#ifndef complexnumbers
#define complexnumbers

#include <iostream>

class Complex
{
private:
    double mRe;
    double mIm;

public:
    Complex();
    Complex(double, double = 0);
    Complex(const Complex &);
    double getRe() const;
    double getIm() const;
    double mod() const;
    double arg() const;
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
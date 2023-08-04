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
    Complex(double, double);
    double mod() const;
    double arg() const;
    Complex pow_n(double) const;
    Complex &operator=(const Complex &);
    Complex operator-() const;
    Complex operator+(const Complex &);
    Complex operator-(const Complex &);
    friend std::ostream &operator<<(std::ostream &, const Complex &);
};

#endif complexnumbers
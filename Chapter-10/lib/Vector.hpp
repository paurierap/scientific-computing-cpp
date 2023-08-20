#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Matrix.hpp"
#include <iostream>

class Vector
{
    friend class Matrix;

private:
    double *mData;
    int mSize;

public:
    Vector(int);
    Vector(const Vector &);
    ~Vector();
    int getSize() const;
    double &operator[](int);
    double read(int) const;
    double &operator()(int);
    Vector &operator=(const Vector &);
    Vector operator+() const;
    Vector operator-() const;
    Vector operator+(const Vector &) const;
    Vector operator-(const Vector &) const;
    Vector operator*(const Matrix &) const;
    Vector operator*(double) const;
    double norm(int = 2) const;
    friend int length(const Vector &);
    friend std::ostream &operator<<(std::ostream, const Vector &);
};

int length(const Vector &);
std::ostream &operator<<(std::ostream &, const Vector &);

#endif
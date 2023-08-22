#ifndef VECTOR_HPP
#define VECTOR_HPP

// IMPORTANT! This class includes the declaration from Matrix.hpp BEFORE declaring Matrix, so the method in Matrix.hpp that has a Vector argument (overloaded operator*), does not recognise the type Vector. It has to be forward-declared, and then we can proceed with the rest of the details.

class Vector;

#include "Matrix.hpp"
#include <iostream>

class Vector
{

    // Friend class to access private variables to overload the operator*
    friend class Matrix;

private:
    double *mData;
    int mSize;

public:
    Vector(int);            // Constructor
    Vector(const Vector &); // Copy constructor
    ~Vector();              // Destructor
    int getSize() const;
    double &operator[](int);
    double read(int) const;
    double &operator()(int);
    Vector &operator=(const Vector &); // Copy assignment
    Vector &operator+=(const Vector &);
    Vector &operator-=(const Vector &);
    const Vector operator+() const;
    const Vector operator-() const;
    friend Vector operator+(const Vector &, const Vector &);
    friend Vector operator-(const Vector &, const Vector &);
    friend Vector operator*(const Vector &, double);
    friend Vector operator*(double, const Vector &);
    // const Vector operator+(const Vector &) const;
    // const Vector operator-(const Vector &) const;
    const Vector operator*(const Matrix &) const;
    // const Vector operator*(double) const;
    double norm(int = 2) const;
    friend int length(const Vector &);
    friend std::ostream &operator<<(std::ostream, const Vector &);
};

Vector operator+(const Vector &, const Vector &);
Vector operator-(const Vector &, const Vector &);
Vector operator*(const Vector &, double);
Vector operator*(double, const Vector &);
int length(const Vector &);
std::ostream &operator<<(std::ostream &, const Vector &);

#endif
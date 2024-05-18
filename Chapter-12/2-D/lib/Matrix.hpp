#ifndef MATRIX_HPP
#define MATRIX_HPP

// IMPORTANT! This class includes the declaration from Vector.hpp BEFORE declaring Matrix, so the method in Vector.hpp that has a Matrix argument (overloaded operator*), does not recognise the type Matrix. It has to be forward-declared, and then we can proceed with the rest of the details.

class Matrix;

#include "Vector.hpp"
#include <iostream>

class Matrix
{

    // Friend class to access private variables to overload the operator*
    friend class Vector;

private:
    int mRows, mCols;
    double **mData;

public:
    Matrix(int);
    Matrix(int, int);
    Matrix(const Matrix &);
    ~Matrix();
    int getRows() const;
    int getCols() const;
    double &operator()(int, int);
    Matrix &operator=(const Matrix &);

    // Trick: define operators +=, -=, etc. to later define +, - (see implementations)
    Matrix &operator+=(const Matrix &);
    Matrix &operator-=(const Matrix &);
    Matrix &operator*=(const Matrix &);
    Matrix &operator+=(double);
    Matrix &operator-=(double);
    Matrix &operator*=(double);
    Matrix operator-() const;

    // It is good practice to overload binary arithmetic operators using friend functions (also helps with symmetry issues with different data types)
    friend Matrix operator+(const Matrix &, const Matrix &);
    friend Matrix operator-(const Matrix &, const Matrix &);
    friend Matrix operator*(const Matrix &, const Matrix &);
    friend Matrix operator+(const Matrix &, double);
    friend Matrix operator-(const Matrix &, double);
    friend Matrix operator*(const Matrix &, double);
    friend Matrix operator+(double, const Matrix &);
    friend Matrix operator-(double, const Matrix &);
    friend Matrix operator*(double, const Matrix &);
    // Matrix operator+(const Matrix &) const;
    // Matrix operator-(const Matrix &) const;
    // Matrix operator*(const Matrix &) const;
    Vector operator*(const Vector &) const;
    // Matrix operator+(double) const;
    // Matrix operator-(double) const;
    // Matrix operator*(double) const;
    double det() const;
    friend std::ostream &operator<<(std::ostream &, const Matrix &);
};

// Friend classes need to be declared besides their 'friend definition'
Matrix operator+(const Matrix &, const Matrix &);
Matrix operator-(const Matrix &, const Matrix &);
Matrix operator*(const Matrix &, const Matrix &);
Matrix operator+(const Matrix &, double);
Matrix operator-(const Matrix &, double);
Matrix operator*(const Matrix &, double);
Matrix operator+(double, const Matrix &);
Matrix operator-(double, const Matrix &);
Matrix operator*(double, const Matrix &);
std::ostream &operator<<(std::ostream &, const Matrix &);

#endif
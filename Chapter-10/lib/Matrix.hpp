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
    Matrix operator-() const;
    Matrix operator+(const Matrix &) const;
    Matrix operator-(const Matrix &) const;
    Matrix operator*(const Matrix &) const;
    Vector operator*(const Vector &) const;
    Matrix operator+(double) const;
    Matrix operator-(double) const;
    Matrix operator*(double) const;
    double det() const;
    friend std::ostream &operator<<(std::ostream &, const Matrix &);
};

std::ostream &operator<<(std::ostream &, const Matrix &);

#endif
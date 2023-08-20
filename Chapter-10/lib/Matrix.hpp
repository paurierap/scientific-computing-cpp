#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Vector.hpp"
#include <iostream>

class Matrix
{
    friend class Vector;

private:
    int mRows, mCols;
    double **mData;

public:
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
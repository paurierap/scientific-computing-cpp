#ifndef matrix
#define matrix

#include <iostream>

class Matrix
{
private:
    int size;
    double **mat_els;
    void allocate();

public:
    Matrix();
    Matrix(const Matrix &);
    Matrix(double, double, double, double);
    ~Matrix();
    double det() const;
    Matrix inv() const;
    Matrix &operator=(const Matrix &);
    Matrix operator-() const;
    Matrix operator+(const Matrix &) const;
    Matrix operator-(const Matrix &) const;
    Matrix operator*(const double &) const;
    friend std::ostream &operator<<(std::ostream &, const Matrix &);
};

#endif
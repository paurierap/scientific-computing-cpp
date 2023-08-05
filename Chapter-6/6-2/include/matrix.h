#ifndef matrix
#define matrix

class Matrix
{
private:
    int n;
    double **mat_els;

public:
    Matrix(double);
    Matrix(const Matrix &);
    Matrix(double, double, double, double);
    ~Matrix();
    double det() const;
    Matrix inv() const;
    Matrix &operator=(const Matrix &);
    Matrix operator-();
    Matrix operator+(const Matrix &);
    Matrix operator-(const Matrix &);
    Matrix operator*(const double &);
    Matrix operator*(const Matrix &);
};

#endif
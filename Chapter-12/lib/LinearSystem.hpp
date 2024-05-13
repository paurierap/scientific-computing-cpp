#ifndef LINEARSYSTEM_HPP
#define LINEARSYSTEM_HPP

#include "Matrix.hpp"
#include "Vector.hpp"

class LinearSystem
{
protected:
    int mSize;
    Matrix *mpA;
    Vector *mpb;
    LinearSystem(const LinearSystem &);

public:
    LinearSystem(const Matrix &, const Vector &);
    ~LinearSystem();
    virtual Vector solve();
};

#endif
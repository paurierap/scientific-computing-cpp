#ifndef LINEARSYSTEM_HPP
#define LINEARSYSTEM_HPP

#include "Matrix.hpp"
#include "Vector.hpp"

class LinearSystem
{
private:
    int mSize;
    Matrix *mpA;
    Vector *mpb;

public:
    LinearSystem(Matrix, Vector);
    ~LinearSystem();
    Vector solve();
};

#endif
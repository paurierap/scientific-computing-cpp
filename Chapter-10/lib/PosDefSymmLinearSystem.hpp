#ifndef POSDEFSYMMLINEARSYSTEM_HPP
#define POSDEFSYMMLINEARSYSTEM_HPP

#include "LinearSystem.hpp"

class PosDefSymmLinearSystem : public LinearSystem
{
public:
    // Inherit constructor, C++11 notation.
    PosDefSymmLinearSystem(const Matrix &, const Vector &);
    //~PosDefSymmLinearSystem();
    Vector solve();
};

#endif
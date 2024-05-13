#ifndef BOUNDARYCONDITIONSHEADER
#define BOUNDARYCONDITIONSHEADER

class BoundaryConditions
{
public:
    friend class BvpOde;

private:
    bool mLhsBcisDirichlet;
    bool mRhsBcisDirichlet;
    bool mLhsBcisNeumann;
    bool mRhsBcisNeumann;
    double mLhsBcValue;
    double mRhsBcValue;

public:
    BoundaryConditions();
    void setLhsDirichletBc(double lhsValue);
    void setRhsDirichletBc(double rhsValue);
    void setLhsNeumannBc(double lhsDerivValue);
    void setRhsNeumannBc(double rhsDerivValue);
};

#endif
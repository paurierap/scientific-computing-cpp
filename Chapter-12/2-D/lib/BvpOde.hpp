#ifndef BVPODEHEADER
#define BVPODEHEADER

#include <string>
#include <vector>
#include "FiniteDifferenceGrid.hpp"
#include "SecondOrderOde.hpp"
#include "BoundaryConditions.hpp"
#include "LinearSystem.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Node.hpp"

class BvpOde
{
private:
    BvpOde(const BvpOde& otherBvpOde) {}

    FiniteDifferenceGrid *mGrid;
    SecondOrderOde *mOde;
    BoundaryConditions *mBCs;
    int mNumNodes;
    Vector *mSol;
    Vector *mRhs;
    Matrix *mLhs;
    LinearSystem *mLinearSystem;
    
    // Specify output file name
    std::string mFilename;

    void PopulateLhs();
    void PopulateRhs();
    void ApplyBCs();
public:
    BvpOde(SecondOrderOde* pOde, BoundaryConditions* pBcs, int numNodes);
    ~BvpOde();
    void setGrid(const std::vector<Node>&);
    void setFilename(const std::string& name)
    {
        mFilename = name;
    }
    void Solve();
    void WriteSolutionFile();
};

#endif
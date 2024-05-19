#include "BvpOde.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <cmath>

// Constructor:
BvpOde::BvpOde(SecondOrderOde* pOde, BoundaryConditions* pBcs, int XnumNodes, int YnumNodes) : 
mOde(pOde), mBCs(pBcs), mXNumNodes(XnumNodes), mYNumNodes(YnumNodes)
{
    // Ensure number of nodes is strictly positive:
    assert(mXNumNodes > 0 && mYNumNodes > 0);

    // Ensure ODE is well-defined;
    assert(mOde->mCoeffUxxisSet && mOde->mCoeffUyyisSet && mOde->mRhsFunisSet && 
           mOde->mXminisSet && mOde->mXmaxisSet && mOde->mYminisSet && mOde->mYmaxisSet);

    // Allocate the rest of data members:
    mGrid = new FiniteDifferenceGrid(mXNumNodes, mYNumNodes, mOde->mXmin, mOde->mXmax, mOde->mYmin, mOde->mYmax);
    total_int_nodes = (mXNumNodes - 2)*(mYNumNodes - 2);
    total_b_nodes = 2*(mXNumNodes + mYNumNodes) - 4;
    mSol = new Vector(total_int_nodes);
    mRhs = new Vector(total_int_nodes);
    mLhs = new Matrix(total_int_nodes);

    // Initialize with nullptr:
    mLinearSystem = nullptr;

    // Default file name:
    mFilename = "solution.dat";
}

// Destructor:
BvpOde::~BvpOde() 
{

    // Every new goes with a delete:
    delete mGrid;
    delete mSol;
    delete mRhs;
    delete mLhs;
    if (mLinearSystem)
    {
        delete mLinearSystem;
    }
}

// Populate RHS vector:
void BvpOde::PopulateRhs()
{

    for (int i = 0; i < total_int_nodes; i++)
    {
        (*mRhs)(i + 1) = mOde->mpRhsFun(mGrid->intNodes[i].x, mGrid->intNodes[i].y);
    }

    std::cout << "RHS populated.\n";
}

// Populate LHS matrix:
void BvpOde::PopulateLhs()
{
    
    for (int j = 0; j < total_int_nodes; j++)
    {
        int i = mGrid->intNodes[j].pos;
        int north = mGrid->intNodes[j].north;
        int east = mGrid->intNodes[j].east;
        int south = mGrid->intNodes[j].south;
        int west = mGrid->intNodes[j].west;

        (*mLhs)(i,i) = 0;
        (*mLhs)(i,north) = 0;
        (*mLhs)(i,east) = 0;
        (*mLhs)(i,south) = 0;
        (*mLhs)(i,west) = 0;
    }

    std::cout << "LHS populated.\n"; 
}

// Apply BCs to indices i=1 and i=N:
void BvpOde::ApplyBCs()
{
    /*
    bool LhsBC = false;
    bool RhsBC = false;

    if (mBCs->mLhsBcisDirichlet)
    {
        (*mRhs)(1) = mBCs->mLhsBcValue;
        (*mLhs)(1,1) = 1.;
        LhsBC = true;
    }

    if (mBCs->mRhsBcisDirichlet)
    {
        (*mRhs)(mNumNodes) = mBCs->mRhsBcValue;
        (*mLhs)(mNumNodes,mNumNodes) = 1.;
        RhsBC = true;
    }

    if (mBCs->mLhsBcisNeumann)
    {
        assert(!LhsBC);

        // Forward derivative:
        (*mRhs)(1) = mBCs->mLhsBcValue;
        (*mLhs)(1,1) = -1. / (mGrid->mNodes[1].coordinate - mGrid->mNodes[0].coordinate);
        (*mLhs)(1,2) = 1. / (mGrid->mNodes[1].coordinate - mGrid->mNodes[0].coordinate);
        LhsBC = true;
    }

    if (mBCs->mRhsBcisNeumann)
    {
        assert(!RhsBC);

        // Backward derivative:
        (*mRhs)(mNumNodes) = mBCs->mRhsBcValue;
        (*mLhs)(mNumNodes,mNumNodes-1) = -1. / (mGrid->mNodes[mNumNodes-1].coordinate - mGrid->mNodes[mNumNodes-2].coordinate);
        (*mLhs)(mNumNodes,mNumNodes) = 1. / (mGrid->mNodes[mNumNodes-1].coordinate - mGrid->mNodes[mNumNodes-2].coordinate); 
        RhsBC = true;
    }

    assert(LhsBC);
    assert(RhsBC);
    */
    std::cout << "BCs applied.\n"; 
}

// Solve linear system and assign solution to mSol:
void BvpOde::Solve()
{
    // LHS matrix and RHS vector need to be populated on construction to pass real matrix and vector to LinearSystem:
    PopulateLhs();
    PopulateRhs();
    ApplyBCs();

    // Allocate LinearSystem with fully populated matrix and vector
    mLinearSystem = new LinearSystem(*mLhs, *mRhs);

    // Solve system and write solution into file:
    *mSol = mLinearSystem->solve();
    WriteSolutionFile();
}

// Write solution file:
void BvpOde::WriteSolutionFile()
{
    /*
    std::ofstream outputfile;
    outputfile.open(mFilename);

    for (int i = 0; i < mNumNodes; i++)
    {
        outputfile << mGrid->mNodes[i].coordinate << ", " << mSol->read(i) << std::endl;
    }

    outputfile.close();

    std::cout << "File " << mFilename << " created and filled." << std::endl;
    */
}
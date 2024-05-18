#include "BvpOde.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <cmath>

// Constructor:
BvpOde::BvpOde(SecondOrderOde* pOde, BoundaryConditions* pBcs, int numNodes) : mOde(pOde), mBCs(pBcs), mNumNodes(numNodes)
{
    // Ensure number of nodes is strictly positive:
    assert(mNumNodes > 0);

    // Ensure ODE is well-defined;
    assert(mOde->mCoeffUxxisSet && mOde->mCoeffUxisSet && mOde->mCoeffUisSet &&
           mOde->mRhsFunisSet && mOde->mXminisSet && mOde->mXmaxisSet);

    // Allocate the rest of data members:
    mGrid = new FiniteDifferenceGrid(mNumNodes, mOde->mXmin, mOde->mXmax);
    mSol = new Vector(mNumNodes);
    mRhs = new Vector(mNumNodes);
    mLhs = new Matrix(mNumNodes);

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

    // Loop from indices i=2,...,N-1
    for (int i = 2; i < mNumNodes; i++)
    {
        (*mRhs)(i) = mOde->mpRhsFun(mGrid->mNodes[i-1].coordinate);
    }

    std::cout << "RHS populated.\n";
}

// Populate LHS matrix:
void BvpOde::PopulateLhs()
{
    // Loop from indices i=2,...,N-1
    for (int i = 2; i < mNumNodes; i++)
    {
        double x_pre = mGrid->mNodes[i-2].coordinate;
        double x = mGrid->mNodes[i-1].coordinate;
        double x_post = mGrid->mNodes[i].coordinate;

        (*mLhs)(i,i-1) = 1. / (x_post - x_pre) * (2. * mOde->mCoeffUxx / (x - x_pre) - mOde->mCoeffUx);
        (*mLhs)(i,i) = mOde->mCoeffU - 2. * mOde->mCoeffUxx / (x_post - x_pre) *(1. / (x_post - x) + 1. / (x - x_pre));
        (*mLhs)(i,i+1) = 1. / (x_post - x_pre) * (2. * mOde->mCoeffUxx / (x_post - x) + mOde->mCoeffUx);
    }

    std::cout << "LHS populated.\n"; 
}

// Apply BCs to indices i=1 and i=N:
void BvpOde::ApplyBCs()
{

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
    std::cout << "BCs applied.\n"; 
}

// Set grid using a specified one:
void BvpOde::setGrid(const std::vector<Node>& grid)
{
    mNumNodes = grid.size();

    // Ensure that there are nodes and they correspond with boundary conditions:
    assert(mNumNodes > 0);
    assert(std::fabs(mOde->mXmin - grid[0].coordinate) < 1e-8);
    assert(std::fabs(mOde->mXmax - grid[mNumNodes-1].coordinate) < 1e-8);

    mGrid->setGrid(grid);
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
    std::ofstream outputfile;
    outputfile.open(mFilename);

    for (int i = 0; i < mNumNodes; i++)
    {
        outputfile << mGrid->mNodes[i].coordinate << ", " << mSol->read(i) << std::endl;
    }

    outputfile.close();

    std::cout << "File " << mFilename << " created and filled." << std::endl;
}
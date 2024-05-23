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

    // Ensure ODE is well-defined:
    assert(mOde->mCoeffUxxisSet && mOde->mCoeffUyyisSet && mOde->mRhsFunisSet && 
           mOde->mXminisSet && mOde->mXmaxisSet && mOde->mYminisSet && mOde->mYmaxisSet);

    // Ensure BCs are set:
    assert(pBcs->isTopBCset && pBcs->isBottomBCset && pBcs->isLeftBCset && pBcs->isRightBCset);
    
    // Allocate the rest of data members:
    mGrid = new FiniteDifferenceGrid(mXNumNodes, mYNumNodes, mOde->mXmin, 
                                     mOde->mXmax, mOde->mYmin, mOde->mYmax);
    mSol = new Vector(mXNumNodes * mYNumNodes);
    mRhs = new Vector(mXNumNodes * mYNumNodes);
    mLhs = new Matrix(mXNumNodes * mYNumNodes);

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

// Apply BCs:
void BvpOde::ApplyBCs()
{
    for (auto& node : mGrid->bNodes)
    {
        if (node.isTopBoundary)
        {
            node.u_val = mBCs->mpTopBoundary(node.x);
        }
        else if (node.isBottomBoundary)
        {
            node.u_val = mBCs->mpBottomBoundary(node.x);
        }
        else if (node.isLeftBoundary)
        {
            node.u_val = mBCs->mpLeftBoundary(node.y);
        }
        else if (node.isRightBoundary)
        {
           node.u_val = mBCs->mpRightBoundary(node.y);
        }
    }

    std::cout << "BCs applied.\n";
}

// Populate RHS vector:
void BvpOde::PopulateRhs()
{

    for (auto node : mGrid->intNodes) (*mRhs)(node.pos + 1) = mOde->mpRhsFun(node.x, node.y);
    for (auto node : mGrid->bNodes) (*mRhs)(node.pos + 1) = node.u_val;
    
    std::cout << "RHS populated.\n";
}

// Populate LHS matrix:
void BvpOde::PopulateLhs()
{
    for (auto node : mGrid->intNodes)
    {
        int i = node.pos;

        Node north = mGrid->globalNum[node.north];
        Node east = mGrid->globalNum[node.east];
        Node south = mGrid->globalNum[node.south];
        Node west = mGrid->globalNum[node.west];

        (*mLhs)(i + 1, i + 1) = - 2. * (1. / (east.x - node.x) / (node.x - west.x) + 
                                1. / (north.y - node.y) / (node.y - south.y));
        (*mLhs)(i + 1, node.north + 1) = 2. / (north.y - south.y) / (north.y - node.y);
        (*mLhs)(i + 1, node.east + 1) = 2. / (east.x - west.x) / (east.x - node.x);
        (*mLhs)(i + 1, node.south + 1) = 2. / (north.y - south.y) / (node.y - south.y);
        (*mLhs)(i + 1, node.west + 1) = 2. / (east.x - west.x) / (node.x - west.x);
    }

    for (auto node : mGrid->bNodes) (*mLhs)(node.pos + 1, node.pos + 1) = 1.;

    std::cout << "LHS populated.\n"; 
}

// Solve linear system and assign solution to mSol:
void BvpOde::Solve()
{
    // LHS matrix and RHS vector need to be populated on construction to pass real matrix and vector to LinearSystem:
    ApplyBCs();
    PopulateLhs();
    PopulateRhs();

    // Allocate LinearSystem with fully populated matrix and vector
    mLinearSystem = new LinearSystem(*mLhs, *mRhs);

    // Solve system and write solution into file:
    *mSol = mLinearSystem->solve();
    WriteSolutionFile();
}

// Write grid file:
void BvpOde::getGrid()
{
    std::ofstream xgrid;
    std::ofstream ygrid;
    xgrid.open("x_grid.dat");
    ygrid.open("y_grid.dat");

    for (int i = 0; i < mYNumNodes; i++)
    {
        for (int j = 0; j < mXNumNodes; j++)
        {
            xgrid << mGrid->globalNum[i * mXNumNodes + j].x << " ";
            ygrid << mGrid->globalNum[i * mXNumNodes + j].y << " ";
        }

        xgrid << "\n";
        ygrid << "\n";
    }

    xgrid.close();
    ygrid.close();

    std::cout << "x and y grid files created and filled." << std::endl;
}

// Write solution file:
void BvpOde::WriteSolutionFile()
{
    
    std::ofstream outputfile;
    outputfile.open(mFilename);

    for (int i = 0; i < mYNumNodes; i++)
    {
        for (int j = 0; j < mXNumNodes; j++)
        {
            outputfile << mSol->read(i * mXNumNodes + j) << " ";
        }

        outputfile << "\n" ;
    }

    outputfile.close();

    std::cout << "Solution file " << mFilename << " created and filled." << std::endl;
}
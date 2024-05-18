#include "FiniteDifferenceGrid.hpp"
#include <cassert>
#include <iostream>

FiniteDifferenceGrid::FiniteDifferenceGrid(int numNodes, double xmin, double xmax) : mNumNodes(numNodes)
{

    // Make sure we have stricly positive number of nodes:
    assert(mNumNodes > 0);
    mNodes.reserve(mNumNodes);
    double h = (xmax-xmin)/((double) (mNumNodes-1));

    for (int i = 0; i < mNumNodes; i++)
    {
        Node node;
        node.coordinate = xmin + i*h;
        mNodes[i] = node;
    }

    std::cout << "Finite Difference Grid with " << mNumNodes << " nodes created.\n";
}

// Allow user to provide a grid:
void FiniteDifferenceGrid::setGrid(const std::vector<Node>& grid)
{
    // Clear current grid:
    mNodes.clear();

    // Reserve new memory:
    mNumNodes = grid.size();
    mNodes.reserve(mNumNodes);

    for (int i = 0; i < mNumNodes; i++)
    {
        mNodes[i] = grid[i];
    }
}

// Overloading the output stream insertion << operator
std::ostream &operator<<(std::ostream &output, const FiniteDifferenceGrid &grid)
{
    for (int i = 0; i < grid.mNumNodes; i++)
    {
        output << grid.mNodes[i].coordinate << " ";
    }

    output << "\n";

    return output;
}
#include "FiniteDifferenceGrid.hpp"
#include <cassert>
#include <iostream>
#include <cmath>

FiniteDifferenceGrid::FiniteDifferenceGrid(int XnumNodes, int YnumNodes, double xmin, double xmax, 
                                           double ymin, double ymax) : mXNumNodes(XnumNodes), mYNumNodes(YnumNodes)
{
    int count = 0;
    double hx = (xmax-xmin)/((double) (mXNumNodes-1));
    double hy = (ymax-ymin)/((double) (mYNumNodes-1));
    double eps = 1e-8;

    for (int i = 0; i < mXNumNodes; i++)
    {
        double yi = ymin + i*hy;

        for (int j = 0; j < mYNumNodes; j++)
        {
            double xi = xmin + j*hx;

            // Check whether it lays on the boundary:
            if (fabs(yi - ymin) < eps || fabs(yi - ymax) < eps || fabs(xi - xmin) < eps || fabs(xi - xmax) < eps)
            {
                BoundaryNode node;
                node.x = xi;
                node.y = yi;
                node.pos = count;
                bNodes.push_back(node);
            }
            else
            {
                InteriorNode node;
                node.x = xi;
                node.y = yi;
                node.pos = count;
                node.north = count + mXNumNodes;
                node.east = count + 1;
                node.south = count - mXNumNodes;
                node.west = count - 1;
                intNodes.push_back(node);
            }

            count++;
        }
    }

    std::cout << "Finite Difference Grid with " << mXNumNodes << " nodes in the x direction and ";
    std::cout << mYNumNodes << " nodes in the y direction created.\n";
}

// Overloading the output stream insertion << operator
std::ostream &operator<<(std::ostream &output, const FiniteDifferenceGrid &grid)
{
    output << "Boundary nodes are: ";
    for (auto node : grid.bNodes)
    {
        output << "(" << node.x << ", " << node.y << ") ";
    }
    output << "\n";

    output << "Interior nodes are: ";
    for (auto node : grid.intNodes)
    {
        output << "(" << node.x << ", " << node.y << ") ";
    }
    output << "\n";

    return output;
}
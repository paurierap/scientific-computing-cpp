#ifndef BOUNDARYNODEHEADER
#define BOUNDARYNODEHEADER

#include "Node.hpp"

class BoundaryNode : public Node
{
public:
    int pos;
    double u_val;
    bool isTopBoundary;
    bool isBottomBoundary;
    bool isLeftBoundary;
    bool isRightBoundary;

    BoundaryNode(double x, double y) : Node(x, y)
    {
        isTopBoundary = isBottomBoundary = isLeftBoundary = isRightBoundary = false;
    }
};

#endif
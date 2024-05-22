#ifndef INTERIORNODEHEADER
#define INTERIORNODEHEADER

#include "Node.hpp"

class InteriorNode : public Node
{
public:
    int pos;
    int north;
    int east;
    int south;
    int west;

    InteriorNode(double x, double y) : Node(x, y) {}
};

#endif
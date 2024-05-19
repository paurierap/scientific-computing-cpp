#ifndef BOUNDARYNODEHEADER
#define BOUNDARYNODEHEADER

#include "Node.hpp"

class BoundaryNode : public Node
{
public:
    int pos;
    double u_val;
};

#endif
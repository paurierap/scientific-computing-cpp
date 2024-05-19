#ifndef INTERIORNODEHEADER
#define INTERIORNODEHEADER

#include "Node.hpp"

class InteriorNode : public Node
{
public:
    int pos;
    int north, east, south, west;
};

#endif
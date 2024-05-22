#ifndef NODEHEADER
#define NODEHEADER

class Node
{
public:
    double x;
    double y;

    // Default constructor. In principle, it is not necessary, but makes it more
    // convenient to use in a map in FiniteDifferenceGrid, see
    // https://stackoverflow.com/questions/695645/why-does-the-c-map-type-argument-require-an-empty-constructor-when-using :
    Node() : x(0), y(0) {}

    // Convenient constructor:
    Node(double x, double y) : x(x), y(y) {}
    
};

#endif
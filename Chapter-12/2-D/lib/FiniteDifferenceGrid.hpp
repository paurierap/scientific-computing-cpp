#ifndef FINITEDIFFERENCEGRIDHEADER
#define FINITEDIFFERENCEGRIDHEADER

#include <vector>
#include "BoundaryNode.hpp"
#include "InteriorNode.hpp"
#include <iostream>

class FiniteDifferenceGrid
{  
public:
    friend class BvpOde;
private:
    int mXNumNodes, mYNumNodes;
    std::vector<InteriorNode> intNodes;
    std::vector<BoundaryNode> bNodes;
public:
    FiniteDifferenceGrid(int XnumNodes, int YnumNodes, double xmin, double xmax, double ymin, double ymax);
    friend std::ostream &operator<<(std::ostream&, const FiniteDifferenceGrid&);
};

#endif
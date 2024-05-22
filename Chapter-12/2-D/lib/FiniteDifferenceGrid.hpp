#ifndef FINITEDIFFERENCEGRIDHEADER
#define FINITEDIFFERENCEGRIDHEADER

#include <vector>
#include <map>
#include "BoundaryNode.hpp"
#include "InteriorNode.hpp"

class FiniteDifferenceGrid
{  
public:
    friend class BvpOde;
private:
    int mXNumNodes, mYNumNodes;
    std::vector<InteriorNode> intNodes;
    std::vector<BoundaryNode> bNodes;

    // Map global numbering to node:
    std::map<int, Node> globalNum;
public:
    FiniteDifferenceGrid(int XnumNodes, int YnumNodes, double xmin, double xmax, double ymin, double ymax);
};

#endif
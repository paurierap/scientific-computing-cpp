#ifndef FINITEDIFFERENCEGRIDHEADER
#define FINITEDIFFERENCEGRIDHEADER

#include <vector>
#include "Node.hpp"
#include <iostream>

class FiniteDifferenceGrid
{  
public:
    friend class BvpOde;
private:
    int mNumNodes;
    std::vector<Node> mNodes;
public:
    FiniteDifferenceGrid(int numNodes, double xmin, double xmax);
    void setGrid(const std::vector<Node>&);
    friend std::ostream &operator<<(std::ostream&, const FiniteDifferenceGrid&);
};

#endif
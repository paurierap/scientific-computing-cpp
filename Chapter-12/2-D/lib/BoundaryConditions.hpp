#ifndef BOUNDARYCONDITIONSHEADER
#define BOUNDARYCONDITIONSHEADER

class BoundaryConditions
{
public:
    friend class BvpOde;

private:
    bool isTopBCset;
    bool isBottomBCset;
    bool isLeftBCset;
    bool isRightBCset;
    double (*mpTopBoundary)(double);
    double (*mpBottomBoundary)(double);
    double (*mpLeftBoundary)(double);
    double (*mpRightBoundary)(double);

public:
    BoundaryConditions();
    void setTopBc(double (*TopBoundary)(double));
    void setBottomBc(double (*BottomBoundary)(double));
    void setLeftBc(double (*LeftBoundary)(double));
    void setRightBc(double (*RightBoundary)(double));
};

#endif
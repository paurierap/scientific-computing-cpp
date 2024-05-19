#ifndef SECONDORDERODEHEADER
#define SECONDORDERODEHEADER

class SecondOrderOde
{
    friend class BvpOde;
private:

    // Coefficients and RHS function
    double mCoeffUxx;
    bool mCoeffUxxisSet;
    double mCoeffUyy;
    bool mCoeffUyyisSet;
    double (*mpRhsFun) (double x, double y);
    bool mRhsFunisSet;

    // Grid delimitators
    double mXmin;
    bool mXminisSet;
    double mXmax;
    bool mXmaxisSet;
    double mYmin;
    bool mYminisSet;
    double mYmax;
    bool mYmaxisSet;

public:

    // Especialized constructor commented for the sake of exercise 12.3:
    /*SecondOrderOde(double coeffUxx, double coeffUyy, double (*Rhsfun) (double x, double y),
                   double xmin, double xmax, double ymin, double ymax) : mCoeffUxx(coeffUxx), 
                   mCoeffUyy(coeffUyy), mpRhsFun(Rhsfun), mXmin(xmin), mXmax(xmax),
                   mYmin(ymin), mYmax(ymax){}*/
    SecondOrderOde()
    {
        mCoeffUxxisSet = mCoeffUyyisSet = mRhsFunisSet = 
        mXminisSet = mXmaxisSet = mYminisSet = mYmaxisSet = false;
    }
    void setCoeffofUxx(double coeffUxx)
    {
        mCoeffUxx = coeffUxx;
        mCoeffUxxisSet = true;
    }
    void setCoeffofUyy(double coeffUyy)
    {
        mCoeffUyy = coeffUyy;
        mCoeffUyyisSet = true;
    }
    void setRhsFun(double (*Rhsfun) (double x, double y))
    {
        mpRhsFun = Rhsfun;
        mRhsFunisSet = true;
    }
    void setXmin(double Xmin)
    {
        mXmin = Xmin;
        mXminisSet = true;
    }
    void setXmax(double Xmax)
    {
        mXmax = Xmax;
        mXmaxisSet = true;
    }
    void setYmin(double Ymin)
    {
        mYmin = Ymin;
        mYminisSet = true;
    }
    void setYmax(double Ymax)
    {
        mYmax = Ymax;
        mYmaxisSet = true;
    }
};

#endif
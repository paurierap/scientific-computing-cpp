#ifndef SECONDORDERODEHEADER
#define SECONDORDERODEHEADER

class SecondOrderOde
{
    friend class BvpOde;
private:
    double mCoeffUxx;
    bool mCoeffUxxisSet;
    double mCoeffUx;
    bool mCoeffUxisSet;
    double mCoeffU;
    bool mCoeffUisSet;
    double (*mpRhsFun) (double x);
    bool mRhsFunisSet;

    double mXmin;
    bool mXminisSet;
    double mXmax;
    bool mXmaxisSet;

public:

    // Especialized constructor commented for the sake of exercise 12.3:
    /*SecondOrderOde(double coeffUxx, double coeffUx, 
                   double coeffU, double (*Rhsfun) (double x),
                   double xmin, double xmax) : mCoeffUxx(coeffUxx), mCoeffUx(coeffUx), 
                   mCoeffU(coeffU), mpRhsFun(Rhsfun), mXmin(xmin), mXmax(xmax) {}*/
    SecondOrderOde()
    {
        mCoeffUxxisSet = mCoeffUxisSet = mCoeffUisSet = 
        mRhsFunisSet = mXminisSet = mXmaxisSet = false;
    }
    void setCoeffofUxx(double coeffUxx)
    {
        mCoeffUxx = coeffUxx;
        mCoeffUxxisSet = true;
    }
    void setCoeffofUx(double coeffUx)
    {
        mCoeffUx = coeffUx;
        mCoeffUxisSet = true;
    }
    void setCoeffofU(double coeffU)
    {
        mCoeffU = coeffU;
        mCoeffUisSet = true;
    }
    void setRhsFun(double (*Rhsfun) (double x))
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
};

#endif
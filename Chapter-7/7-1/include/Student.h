#ifndef STUDENTHPP
#define STUDENTHPP

#include <string>

class Student
{
protected:
    double libfine;

public:
    std::string name;
    double tuition;
    Student();
    Student(std::string);
    Student(std::string, double, double);
    void setLibfine(double);
    double getLibfine() const;
    virtual double total_owed() const;
};

#endif
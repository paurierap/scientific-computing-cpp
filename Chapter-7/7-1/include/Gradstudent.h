#ifndef GRADSTUDENTHPP
#define GRADSTUDENTHPP

#include "Student.h"
#include <string>

class Gradstudent : public Student
{
public:
    std::string worktime;
    virtual double total_owed() const;
};

#endif
#ifndef GRADSTUDENTHPP
#define GRADSTUDENTHPP

#include "Student.hpp"
#include <string>

class Gradstudent : public Student
{
public:
    std::string worktime;
    virtual double total_owed() const;
};

#endif
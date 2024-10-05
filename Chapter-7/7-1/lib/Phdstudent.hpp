#ifndef PHDSTUDENTHPP
#define PHDSTUDENTHPP

#include "Gradstudent.hpp"
#include <string>

class Phdstudent : public Gradstudent
{
public:
    double total_owed() const;
};

#endif
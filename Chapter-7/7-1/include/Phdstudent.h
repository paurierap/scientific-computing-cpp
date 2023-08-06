#ifndef PHDSTUDENTHPP
#define PHDSTUDENTHPP

#include "Gradstudent.h"
#include <string>

class Phdstudent : public Gradstudent
{
public:
    double total_owed() const;
};

#endif
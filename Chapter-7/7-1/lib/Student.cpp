#include "../include/Student.h"
#include <cassert>

Student::Student() : libfine(0), tuition(0)
{
    name = "unspecified";
}

Student::Student(std::string fullname) : name(fullname), libfine(0), tuition(0) {}

Student::Student(std::string fullname, double fines, double fees) : name(fullname), libfine(fines), tuition(fees) {}

void Student::setLibfine(double amount)
{
    assert(amount >= 0);
    libfine = amount;
}

double Student::getLibfine() const
{
    return libfine;
}

double Student::total_owed() const
{
    return libfine + tuition;
}
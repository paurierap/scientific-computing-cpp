#include "Exception.hpp"
#include <iostream>

Exception::Exception(std::string tag, std::string prob) : mTag(tag), mProblem(prob)
{
}

void Exception::PrintDebug() const
{
    std::cerr << "** Error (" << mTag << ") ** \n";
    std::cerr << "Problem: " << mProblem << "\n\n";
}
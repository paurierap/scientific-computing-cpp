#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>

class Exception
{
protected:
    std::string mTag, mProblem;

public:
    Exception(std::string, std::string);
    void PrintDebug() const;
};

#endif

#ifndef OUTOFRANGEEXCEPTION_HPP
#define OUTOFRANGEEXCEPTION_HPP

#include "Exception.hpp"
#include <string>

class OutOfRangeException : public Exception
{
public:
    OutOfRangeException(std::string);
};

#endif
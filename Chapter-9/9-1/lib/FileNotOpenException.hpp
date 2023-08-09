#ifndef FILENOTOPENEXCEPTION_HPP
#define FILENOTOPENEXCEPTION_HPP

#include "Exception.hpp"
#include <string>

class FileNotOpenException : public Exception
{
public:
    FileNotOpenException(std::string);
};

#endif
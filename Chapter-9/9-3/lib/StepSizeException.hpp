#include <exception>

class StepSizeException : public std::exception
{
    const char *what() const throw();
};
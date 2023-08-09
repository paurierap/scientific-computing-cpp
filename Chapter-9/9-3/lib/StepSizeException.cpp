#include "StepSizeException.hpp"

const char *StepSizeException::what() const throw()
{
    return "\n** Value of y is out of bounds **\n StepSize may be too large: trying half the current value.\n";
}
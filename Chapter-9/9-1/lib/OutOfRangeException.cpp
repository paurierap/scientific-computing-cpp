#include "OutOfRangeException.hpp"
#include <string>

OutOfRangeException::OutOfRangeException(std::string prob) : Exception("RANGE", prob) {}
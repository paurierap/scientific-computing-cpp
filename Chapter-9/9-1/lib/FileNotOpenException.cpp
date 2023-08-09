#include "FileNotOpenException.hpp"
#include <string>

FileNotOpenException::FileNotOpenException(std::string prob) : Exception("FILE", prob) {}

#include <cxxtest/TestSuite.h>
#include "complex.hpp"

class ComplexTestSuite : public CxxTest::TestSuite
{
public:
    void TestDefaultConstructor();
    void TestCustomisedConstructor();
    void TestCalculatePower();
    void TestAgainstSTDLibrary();
};
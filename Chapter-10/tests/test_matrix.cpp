/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_LinearSystemTestSuite_init = false;
#include "LinearSystemTestSuite.hpp"

static LinearSystemTestSuite suite_LinearSystemTestSuite;

static CxxTest::List Tests_LinearSystemTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_LinearSystemTestSuite( "LinearSystemTestSuite.hpp", 8, "LinearSystemTestSuite", suite_LinearSystemTestSuite, Tests_LinearSystemTestSuite );

static class TestDescription_suite_LinearSystemTestSuite_TestSolver : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_LinearSystemTestSuite_TestSolver() : CxxTest::RealTestDescription( Tests_LinearSystemTestSuite, suiteDescription_LinearSystemTestSuite, 11, "TestSolver" ) {}
 void runTest() { suite_LinearSystemTestSuite.TestSolver(); }
} testDescription_suite_LinearSystemTestSuite_TestSolver;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";

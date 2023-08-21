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
bool suite_MatrixTestSuite_init = false;
#include "MatrixTestSuite.hpp"

static MatrixTestSuite suite_MatrixTestSuite;

static CxxTest::List Tests_MatrixTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MatrixTestSuite( "MatrixTestSuite.hpp", 8, "MatrixTestSuite", suite_MatrixTestSuite, Tests_MatrixTestSuite );

static class TestDescription_suite_MatrixTestSuite_TestDefaultConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestDefaultConstructor() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 11, "TestDefaultConstructor" ) {}
 void runTest() { suite_MatrixTestSuite.TestDefaultConstructor(); }
} testDescription_suite_MatrixTestSuite_TestDefaultConstructor;

static class TestDescription_suite_MatrixTestSuite_TestCustomisedConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestCustomisedConstructor() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 17, "TestCustomisedConstructor" ) {}
 void runTest() { suite_MatrixTestSuite.TestCustomisedConstructor(); }
} testDescription_suite_MatrixTestSuite_TestCustomisedConstructor;

static class TestDescription_suite_MatrixTestSuite_TestGetRows : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestGetRows() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 32, "TestGetRows" ) {}
 void runTest() { suite_MatrixTestSuite.TestGetRows(); }
} testDescription_suite_MatrixTestSuite_TestGetRows;

static class TestDescription_suite_MatrixTestSuite_TestGetCols : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestGetCols() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 38, "TestGetCols" ) {}
 void runTest() { suite_MatrixTestSuite.TestGetCols(); }
} testDescription_suite_MatrixTestSuite_TestGetCols;

static class TestDescription_suite_MatrixTestSuite_TestDeterminant : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTestSuite_TestDeterminant() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 44, "TestDeterminant" ) {}
 void runTest() { suite_MatrixTestSuite.TestDeterminant(); }
} testDescription_suite_MatrixTestSuite_TestDeterminant;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";

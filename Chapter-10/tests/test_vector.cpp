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
bool suite_VectorTestSuite_init = false;
#include "VectorTestSuite.hpp"

static VectorTestSuite suite_VectorTestSuite;

static CxxTest::List Tests_VectorTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_VectorTestSuite( "VectorTestSuite.hpp", 6, "VectorTestSuite", suite_VectorTestSuite, Tests_VectorTestSuite );

static class TestDescription_suite_VectorTestSuite_TestDefaultConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTestSuite_TestDefaultConstructor() : CxxTest::RealTestDescription( Tests_VectorTestSuite, suiteDescription_VectorTestSuite, 9, "TestDefaultConstructor" ) {}
 void runTest() { suite_VectorTestSuite.TestDefaultConstructor(); }
} testDescription_suite_VectorTestSuite_TestDefaultConstructor;

static class TestDescription_suite_VectorTestSuite_TestCustomisedConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTestSuite_TestCustomisedConstructor() : CxxTest::RealTestDescription( Tests_VectorTestSuite, suiteDescription_VectorTestSuite, 15, "TestCustomisedConstructor" ) {}
 void runTest() { suite_VectorTestSuite.TestCustomisedConstructor(); }
} testDescription_suite_VectorTestSuite_TestCustomisedConstructor;

static class TestDescription_suite_VectorTestSuite_TestGetSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTestSuite_TestGetSize() : CxxTest::RealTestDescription( Tests_VectorTestSuite, suiteDescription_VectorTestSuite, 27, "TestGetSize" ) {}
 void runTest() { suite_VectorTestSuite.TestGetSize(); }
} testDescription_suite_VectorTestSuite_TestGetSize;

static class TestDescription_suite_VectorTestSuite_TestLength : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTestSuite_TestLength() : CxxTest::RealTestDescription( Tests_VectorTestSuite, suiteDescription_VectorTestSuite, 33, "TestLength" ) {}
 void runTest() { suite_VectorTestSuite.TestLength(); }
} testDescription_suite_VectorTestSuite_TestLength;

static class TestDescription_suite_VectorTestSuite_TestNorm : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTestSuite_TestNorm() : CxxTest::RealTestDescription( Tests_VectorTestSuite, suiteDescription_VectorTestSuite, 39, "TestNorm" ) {}
 void runTest() { suite_VectorTestSuite.TestNorm(); }
} testDescription_suite_VectorTestSuite_TestNorm;

static class TestDescription_suite_VectorTestSuite_TestEqualOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTestSuite_TestEqualOperator() : CxxTest::RealTestDescription( Tests_VectorTestSuite, suiteDescription_VectorTestSuite, 52, "TestEqualOperator" ) {}
 void runTest() { suite_VectorTestSuite.TestEqualOperator(); }
} testDescription_suite_VectorTestSuite_TestEqualOperator;

static class TestDescription_suite_VectorTestSuite_TestMatlabNotation : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTestSuite_TestMatlabNotation() : CxxTest::RealTestDescription( Tests_VectorTestSuite, suiteDescription_VectorTestSuite, 67, "TestMatlabNotation" ) {}
 void runTest() { suite_VectorTestSuite.TestMatlabNotation(); }
} testDescription_suite_VectorTestSuite_TestMatlabNotation;

static class TestDescription_suite_VectorTestSuite_TestAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTestSuite_TestAddition() : CxxTest::RealTestDescription( Tests_VectorTestSuite, suiteDescription_VectorTestSuite, 79, "TestAddition" ) {}
 void runTest() { suite_VectorTestSuite.TestAddition(); }
} testDescription_suite_VectorTestSuite_TestAddition;

static class TestDescription_suite_VectorTestSuite_TestSubtraction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTestSuite_TestSubtraction() : CxxTest::RealTestDescription( Tests_VectorTestSuite, suiteDescription_VectorTestSuite, 96, "TestSubtraction" ) {}
 void runTest() { suite_VectorTestSuite.TestSubtraction(); }
} testDescription_suite_VectorTestSuite_TestSubtraction;

static class TestDescription_suite_VectorTestSuite_TestScalarMultiplication : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTestSuite_TestScalarMultiplication() : CxxTest::RealTestDescription( Tests_VectorTestSuite, suiteDescription_VectorTestSuite, 112, "TestScalarMultiplication" ) {}
 void runTest() { suite_VectorTestSuite.TestScalarMultiplication(); }
} testDescription_suite_VectorTestSuite_TestScalarMultiplication;

static class TestDescription_suite_VectorTestSuite_TestAgainstSTDLibrary : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTestSuite_TestAgainstSTDLibrary() : CxxTest::RealTestDescription( Tests_VectorTestSuite, suiteDescription_VectorTestSuite, 129, "TestAgainstSTDLibrary" ) {}
 void runTest() { suite_VectorTestSuite.TestAgainstSTDLibrary(); }
} testDescription_suite_VectorTestSuite_TestAgainstSTDLibrary;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";

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
bool suite_ComplexTestSuite_init = false;
#include "ComplexTestSuite.hpp"

static ComplexTestSuite suite_ComplexTestSuite;

static CxxTest::List Tests_ComplexTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ComplexTestSuite( "ComplexTestSuite.hpp", 5, "ComplexTestSuite", suite_ComplexTestSuite, Tests_ComplexTestSuite );

static class TestDescription_suite_ComplexTestSuite_TestDefaultConstructorWhiteBox : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ComplexTestSuite_TestDefaultConstructorWhiteBox() : CxxTest::RealTestDescription( Tests_ComplexTestSuite, suiteDescription_ComplexTestSuite, 8, "TestDefaultConstructorWhiteBox" ) {}
 void runTest() { suite_ComplexTestSuite.TestDefaultConstructorWhiteBox(); }
} testDescription_suite_ComplexTestSuite_TestDefaultConstructorWhiteBox;

static class TestDescription_suite_ComplexTestSuite_TestCustomisedConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ComplexTestSuite_TestCustomisedConstructor() : CxxTest::RealTestDescription( Tests_ComplexTestSuite, suiteDescription_ComplexTestSuite, 16, "TestCustomisedConstructor" ) {}
 void runTest() { suite_ComplexTestSuite.TestCustomisedConstructor(); }
} testDescription_suite_ComplexTestSuite_TestCustomisedConstructor;

static class TestDescription_suite_ComplexTestSuite_TestCalculateArgumentException : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ComplexTestSuite_TestCalculateArgumentException() : CxxTest::RealTestDescription( Tests_ComplexTestSuite, suiteDescription_ComplexTestSuite, 24, "TestCalculateArgumentException" ) {}
 void runTest() { suite_ComplexTestSuite.TestCalculateArgumentException(); }
} testDescription_suite_ComplexTestSuite_TestCalculateArgumentException;

static class TestDescription_suite_ComplexTestSuite_TestCalculatePower : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ComplexTestSuite_TestCalculatePower() : CxxTest::RealTestDescription( Tests_ComplexTestSuite, suiteDescription_ComplexTestSuite, 31, "TestCalculatePower" ) {}
 void runTest() { suite_ComplexTestSuite.TestCalculatePower(); }
} testDescription_suite_ComplexTestSuite_TestCalculatePower;

static class TestDescription_suite_ComplexTestSuite_TestAgainstSTDLibrary : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ComplexTestSuite_TestAgainstSTDLibrary() : CxxTest::RealTestDescription( Tests_ComplexTestSuite, suiteDescription_ComplexTestSuite, 40, "TestAgainstSTDLibrary" ) {}
 void runTest() { suite_ComplexTestSuite.TestAgainstSTDLibrary(); }
} testDescription_suite_ComplexTestSuite_TestAgainstSTDLibrary;

static class TestDescription_suite_ComplexTestSuite_TestEqualOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ComplexTestSuite_TestEqualOperator() : CxxTest::RealTestDescription( Tests_ComplexTestSuite, suiteDescription_ComplexTestSuite, 55, "TestEqualOperator" ) {}
 void runTest() { suite_ComplexTestSuite.TestEqualOperator(); }
} testDescription_suite_ComplexTestSuite_TestEqualOperator;

static class TestDescription_suite_ComplexTestSuite_TestUnaryOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ComplexTestSuite_TestUnaryOperator() : CxxTest::RealTestDescription( Tests_ComplexTestSuite, suiteDescription_ComplexTestSuite, 64, "TestUnaryOperator" ) {}
 void runTest() { suite_ComplexTestSuite.TestUnaryOperator(); }
} testDescription_suite_ComplexTestSuite_TestUnaryOperator;

static class TestDescription_suite_ComplexTestSuite_TestAdditionOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ComplexTestSuite_TestAdditionOperator() : CxxTest::RealTestDescription( Tests_ComplexTestSuite, suiteDescription_ComplexTestSuite, 73, "TestAdditionOperator" ) {}
 void runTest() { suite_ComplexTestSuite.TestAdditionOperator(); }
} testDescription_suite_ComplexTestSuite_TestAdditionOperator;

static class TestDescription_suite_ComplexTestSuite_TestSubtractionOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ComplexTestSuite_TestSubtractionOperator() : CxxTest::RealTestDescription( Tests_ComplexTestSuite, suiteDescription_ComplexTestSuite, 82, "TestSubtractionOperator" ) {}
 void runTest() { suite_ComplexTestSuite.TestSubtractionOperator(); }
} testDescription_suite_ComplexTestSuite_TestSubtractionOperator;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";

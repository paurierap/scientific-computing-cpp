From the Github page: https://github.com/CxxTest/cxxtest

A Simple Example
----------------

1. Create a test suite header file:

MyTestSuite.h:

  #include <cxxtest/TestSuite.h>

  class MyTestSuite : public CxxTest::TestSuite
  {
  public:
      void testAddition( void )
      {
          TS_ASSERT( 1 + 1 > 1 );
          TS_ASSERT_EQUALS( 1 + 1, 2 );
      }
  };


2. Generate the tests file:

 # cxxtestgen --error-printer -o tests.cpp MyTestSuite.h

3. Compile and run!

  # g++ -o main tests.cpp dependency1.cpp dependency2.cpp
  # ./main
  Running cxxtest tests (1 test).OK!
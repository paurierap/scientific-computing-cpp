// Esta una mica a mitges, la ultima part feia molta mandra.

#include <cxxtest/TestSuite.h>
#include "../lib/Complex.hpp"
#include <cmath>

class ComplexTestSuite : public CxxTest::TestSuite
{
public:
    void TestDefaultConstructorWhiteBox()
    {
        Complex z;

        TS_ASSERT_DELTA(z.mMod, 0.0, 1.0e-16);
        TS_ASSERT_DELTA(z.mArg, 0.0, 1.0e-16);
    }

    void TestCustomisedConstructor()
    {
        Complex z(4, -3);

        TS_ASSERT_DELTA(z.mod(), 5, 1e-8);
        TS_ASSERT_DELTA(z.arg(), -asin(3.0 / 5.0), 1e-8);
    }

    void TestCalculateArgumentException()
    {
        Complex z(0, 0);

        TS_ASSERT_DELTA(z.arg(), 0, 1e-8);
    }

    void TestCalculatePower()
    {
        Complex z(4, -3);
        Complex z2 = z.pow_n(2.);

        TS_ASSERT_DELTA(z.mod() * z.mod(), z2.mod(), 1e-8);
        TS_ASSERT_DELTA(2.0 * z.arg(), z2.arg(), 1e-8);
    }

    void TestAgainstSTDLibrary()
    {
        Complex z(4, -3);
        std::complex<double> zs(4, -3);

        TS_ASSERT_DELTA(z.arg(), arg(zs), 1e-8);
        TS_ASSERT_DELTA(z.mod(), abs(zs), 1e-8);

        z = z.pow_n(5.);
        zs = pow(zs, 5.);

        TS_ASSERT_DELTA(z.arg(), arg(zs), 1e-8);
        TS_ASSERT_DELTA(z.mod(), abs(zs), 1e-8);
    }

    void TestEqualOperator()
    {
        Complex z(2, 3), w;
        w = z;

        TS_ASSERT_DELTA(z.arg(), w.arg(), 1e-8);
        TS_ASSERT_DELTA(z.mod(), w.mod(), 1e-8);
    }

    void TestUnaryOperator()
    {
        Complex z(2, 3);
        z = -z;

        TS_ASSERT_DELTA(real(z), -2, 1e-8);
        TS_ASSERT_DELTA(imag(z), -3, 1e-8);
    }

    void TestAdditionOperator()
    {
        Complex z(2, 3), w(1, 6), s(3, 9), t;
        t = w + z;

        TS_ASSERT_DELTA(s.arg(), t.arg(), 1e-8);
        TS_ASSERT_DELTA(s.mod(), t.mod(), 1e-8);
    }

    void TestSubtractionOperator()
    {
        Complex z(2, 3), w(1, 6), s(-1, 3), t;
        t = w - z;

        TS_ASSERT_DELTA(s.arg(), t.arg(), 1e-8);
        TS_ASSERT_DELTA(s.mod(), t.mod(), 1e-8);
    }
};
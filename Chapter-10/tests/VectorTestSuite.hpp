#include <cxxtest/TestSuite.h>
#include "../lib/Vector.hpp"
#include <cmath>
#include <vector>

class VectorTestSuite : public CxxTest::TestSuite
{
public:
    void TestDefaultConstructor()
    {
        Vector v(10);
        TS_ASSERT_DELTA(v.norm(), 0., 1e-8);
    }

    void TestCustomisedConstructor()
    {
        Vector v(3);
        double w[3] = {2, -1, 6};

        for (int i = 0; i < v.getSize(); ++i)
        {
            v[i] = w[i];
            TS_ASSERT_DELTA(v[i], w[i], 1.e-8);
        }
    }

    void TestGetSize()
    {
        Vector v(8);
        TS_ASSERT_DELTA(v.getSize(), 8, 1.e-8);
    }

    void TestLength()
    {
        Vector v(8);
        TS_ASSERT_DELTA(length(v), 8, 1.e-8);
    }

    void TestNorm()
    {
        Vector v(3);
        double w[3] = {2, -1, 6};

        for (int i = 0; i < v.getSize(); ++i)
        {
            v[i] = w[i];
        }

        TS_ASSERT_DELTA(v.norm(), sqrt(41), 1.e-6);
    }

    void TestEqualOperator()
    {
        Vector v(3), u(3);
        double y[3] = {2, -1, 6};

        for (int i = 0; i < v.getSize(); ++i)
        {
            v[i] = y[i];
        }

        u = v;

        TS_ASSERT_DELTA(u.norm(), v.norm(), 1.e-6);
    }

    void TestMatlabNotation()
    {
        Vector v(3);
        double y[3] = {2, -1, 6};

        for (int i = 0; i < v.getSize(); ++i)
        {
            v[i] = y[i];
            TS_ASSERT_DELTA(v[i], v(i + 1), 1.e-6);
        }
    }

    void TestAddition()
    {
        Vector v(3), u(3), w(3);
        double y[3] = {2, -1, 6}, z[3] = {4, 2, 0};

        for (int i = 0; i < v.getSize(); ++i)
        {
            v[i] = y[i];
            u[i] = z[i];
        }

        w = v + u;

        TS_ASSERT_DELTA(w.norm(), sqrt(73), 1.e-6);
    }

    void TestSubtraction()
    {
        Vector v(3), u(3), w(3);
        double y[3] = {2, -1, 6}, z[3] = {4, 2, 0};

        for (int i = 0; i < v.getSize(); ++i)
        {
            v[i] = y[i];
            u[i] = z[i];
        }

        w = v - u;

        TS_ASSERT_DELTA(w.norm(), sqrt(49), 1.e-6);
    }

    void TestScalarMultiplication()
    {
        Vector v(3);
        double y[3] = {2, -1, 6}, a = 3;

        for (int i = 0; i < v.getSize(); ++i)
        {
            v[i] = y[i];
        }

        v = v * a;

        TS_ASSERT_DELTA(v.norm(), 3 * sqrt(41), 1.e-6);
    }

    void TestAgainstSTDLibrary()
    {
    }
};
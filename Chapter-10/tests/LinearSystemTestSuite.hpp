#include <cxxtest/TestSuite.h>
#include "../lib/Matrix.hpp"
#include "../lib/Vector.hpp"
#include "../lib/LinearSystem.hpp"
#include "../lib/PosDefSymmLinearSystem.hpp"
#include <cmath>
#include <iostream>

class LinearSystemTestSuite : public CxxTest::TestSuite
{
public:
    void TestSolver()
    {
        Matrix A(3, 3);
        Vector b(3), sol(3);

        A(1, 1) = 1;
        A(1, 2) = 1;
        A(1, 3) = 1;
        A(2, 1) = 1;
        A(2, 2) = 1;
        A(2, 3) = 2;
        A(3, 1) = 0;
        A(3, 2) = 5;
        A(3, 3) = 1;

        b(1) = 4;
        b(2) = 6;
        b(3) = 1;

        LinearSystem sys(A, b);
        sol = sys.solve();

        TS_ASSERT_DELTA(sol(1), 2.2, 1.e-6);
        TS_ASSERT_DELTA(sol(2), -0.2, 1.e-6);
        TS_ASSERT_DELTA(sol(3), 2, 1.e-6);
    }

    void TestLargeConditionNumber()
    {
        Matrix a(3, 3);
        Vector b(3), sol(3);

        a(1, 1) = 1;
        a(1, 2) = 0;
        a(1, 3) = 1e7;
        a(2, 1) = 1;
        a(2, 2) = -1;
        a(2, 3) = 0;
        a(3, 1) = 1;
        a(3, 2) = 0;
        a(3, 3) = 1;
        b(1) = 1e7 + 1;
        b(2) = 0;
        b(3) = 2;

        TS_ASSERT_DELTA(a.det(), 1e7 - 1., 1e-8);

        LinearSystem ls(a, b);
        sol = ls.solve();

        for (int i = 0; i < 3; i++)
        {
            TS_ASSERT_DELTA(sol(i + 1), 1, 1e-8);
        }
    }

    void TestSymmetry()
    {
        Matrix a(3, 3);
        Vector b(3), sol(3);

        a(1, 1) = 1;
        a(1, 2) = 0;
        a(1, 3) = 1e7;
        a(2, 1) = 0;
        a(2, 2) = -1;
        a(2, 3) = 0;
        a(3, 1) = 1e7;
        a(3, 2) = 0;
        a(3, 3) = 1;
        b(1) = 1e7 + 1;
        b(2) = 0;
        b(3) = 2;

        PosDefSymmLinearSystem PDls(a, b);
        sol = PDls.solve();
    }
};
#include <cxxtest/TestSuite.h>
#include "../lib/Matrix.hpp"
#include "../lib/Vector.hpp"
#include <cmath>
#include <iostream>
#include <vector>

class MatrixTestSuite : public CxxTest::TestSuite
{
public:
    void TestDefaultConstructor()
    {
        Matrix M(5);
        TS_ASSERT_DELTA(M.det(), 0., 1e-8);
    }

    void TestCustomisedConstructor()
    {
        Matrix M(3, 3);
        double m[3][3] = {{2, -1, 6}, {1, 3, 5}, {0, 8, 12}};

        for (int i = 0; i < M.getRows(); ++i)
        {
            for (int j = 0; j < M.getCols(); ++j)
            {
                M(i + 1, j + 1) = m[i][j];
                TS_ASSERT_DELTA(M(i + 1, j + 1), m[i][j], 1.e-8);
            }
        }
    }

    void TestGetRows()
    {
        Matrix M(6, 3);
        TS_ASSERT_DELTA(M.getRows(), 6, 1.e-8);
    }

    void TestGetCols()
    {
        Matrix M(6, 3);
        TS_ASSERT_DELTA(M.getCols(), 3, 1.e-8);
    }

    void TestDeterminant()
    {
        Matrix M(3, 3);
        double m[3][3] = {{2, -1, 6}, {1, 3, 5}, {0, 8, 12}};

        for (int i = 0; i < M.getRows(); ++i)
        {
            for (int j = 0; j < M.getCols(); ++j)
            {
                M(i + 1, j + 1) = m[i][j];
            }
        }

        TS_ASSERT_DELTA(M.det(), 52, 1.e-6);
    }
};
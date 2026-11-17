// tests_9_2_1.cpp
// Unit-тести Google Test для Завдання 9.2, частина 1, варіант 23
//

#include <gtest/gtest.h>
#include "macros.h"

// Обидві гілки формули побудовані лише з макросів із macros.h
static double w_branch1(double x, double y, double z)   // 1 < z < 3
{
    return MAX(ABS(x) + ABS(y) + ABS(z), CUBE(x));
}

static double w_branch2(double x, double y, double z)   // z > 3
{
    return MIN(2 * x + y, SQR(2 * y - z));
}

// ---------- окремі макроси ----------

TEST(MacroTest, Max)
{
    EXPECT_EQ(MAX(3, 7), 7);
    EXPECT_EQ(MAX(-3, -7), -3);
    EXPECT_EQ(MAX(5, 5), 5);
    EXPECT_DOUBLE_EQ(MAX(2.5, 1.5), 2.5);
}

TEST(MacroTest, Min)
{
    EXPECT_EQ(MIN(3, 7), 3);
    EXPECT_EQ(MIN(-3, -7), -7);
    EXPECT_EQ(MIN(5, 5), 5);
    EXPECT_DOUBLE_EQ(MIN(2.5, 1.5), 1.5);
}

TEST(MacroTest, Abs)
{
    EXPECT_EQ(ABS(-4), 4);
    EXPECT_EQ(ABS(4), 4);
    EXPECT_EQ(ABS(0), 0);
    EXPECT_DOUBLE_EQ(ABS(-2.5), 2.5);
}

TEST(MacroTest, SqrRespectsParentheses)
{
    EXPECT_EQ(SQR(3), 9);
    EXPECT_EQ(SQR(1 + 2), 9);          // а не 1 + 2*2 + 2 = 7
    EXPECT_EQ(SQR(-3), 9);
}

TEST(MacroTest, Cube)
{
    EXPECT_EQ(CUBE(2), 8);
    EXPECT_EQ(CUBE(-2), -8);
    EXPECT_EQ(CUBE(1 + 1), 8);
}

TEST(MacroTest, NestedMacros)
{
    EXPECT_EQ(MAX(ABS(-5), SQR(2)), 5);
    EXPECT_EQ(MIN(ABS(-5), SQR(2)), 4);
}

// ---------- гілка 1: 1 < z < 3 ----------

TEST(Branch1Test, CubeIsLarger)
{
    EXPECT_DOUBLE_EQ(w_branch1(2, 1, 2), 8.0);   // max(5, 8)
}

TEST(Branch1Test, SumOfModulesIsLarger)
{
    EXPECT_DOUBLE_EQ(w_branch1(1, -1, 2), 4.0);  // max(1+1+2, 1)
}

TEST(Branch1Test, NegativeX)
{
    EXPECT_DOUBLE_EQ(w_branch1(-2, -1, 2), 5.0); // max(5, -8)
}

TEST(Branch1Test, AllZeroExceptZ)
{
    EXPECT_DOUBLE_EQ(w_branch1(0, 0, 2), 2.0);   // max(2, 0)
}

// ---------- гілка 2: z > 3 ----------

TEST(Branch2Test, LinearPartIsSmaller)
{
    EXPECT_DOUBLE_EQ(w_branch2(1, 1, 5), 3.0);   // min(3, 9)
}

TEST(Branch2Test, SquarePartIsSmaller)
{
    EXPECT_DOUBLE_EQ(w_branch2(5, 3, 4), 4.0);   // min(13, 4)
}

TEST(Branch2Test, ZeroXY)
{
    EXPECT_DOUBLE_EQ(w_branch2(0, 0, 10), 0.0);  // min(0, 100)
}

TEST(Branch2Test, NegativeValues)
{
    EXPECT_DOUBLE_EQ(w_branch2(-2, -1, 4), -5.0); // min(-5, 36)
}

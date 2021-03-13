#ifndef TEST_SQ_EQ_H
#define TEST_SQ_EQ_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/* using namespace testing; */
extern "C" {
#include "sq_equat.h"
}

TEST(one_solve, suite1)
{
    solves s = solve_equation(1, 0, 0);
    EXPECT_EQ(s.count, 1);
    EXPECT_NEAR(s.x1, 0.0, 0.000001);
}

TEST(one_solve, suite2)
{
    solves s = solve_equation(1, 2, 1);
    EXPECT_EQ(s.count, 1);
    EXPECT_NEAR(s.x1, -1.0, 0.000001);
}

TEST(one_solve, suite3)
{
    solves s = solve_equation(1, -4, 4);
    EXPECT_EQ(s.count, 1);
    EXPECT_NEAR(s.x1, 2.0, 0.000001);
}

TEST(two_solves, suite1)
{
    solves s = solve_equation(1, -5, 6);
    EXPECT_EQ(s.count, 2);
    EXPECT_NEAR(s.x1, 2.0, 0.000001);
    EXPECT_NEAR(s.x2, 3.0, 0.000001);
}

TEST(two_solves, suite2)
{
    solves s = solve_equation(2, 2, -4);
    EXPECT_EQ(s.count, 2);
    EXPECT_NEAR(s.x1, -2.0, 0.000001);
    EXPECT_NEAR(s.x2, 1.0, 0.000001);
}

TEST(two_solves, suite3)
{
    solves s = solve_equation(1, 5, 6);
    EXPECT_EQ(s.count, 2);
    EXPECT_NEAR(s.x1, -3.0, 0.000001);
    EXPECT_NEAR(s.x2, -2.0, 0.000001);
}

TEST(no_solves, suite1)
{
    solves s = solve_equation(1, 2, 3);
    EXPECT_EQ(s.count, 0);
}

TEST(no_solves, suite2)
{
    solves s = solve_equation(6, 6, 9);
    EXPECT_EQ(s.count, 0);
}

TEST(no_solves, suite3)
{
    solves s = solve_equation(-6, -6, -9);
    EXPECT_EQ(s.count, 0);
}

TEST(extra_tests, linear_equation)
{
    solves s = solve_equation(0, 1, 2);
    EXPECT_EQ(s.count, 1);
    EXPECT_NEAR(s.x1, -2.0, 0.000001);
}

TEST(extra_tests, zero)
{
    solves s = solve_equation(0, 0, 1);
    EXPECT_EQ(s.count, 0);
}

TEST(extra_tests, infinity)
{
    solves s = solve_equation(0, 0, 0);
    EXPECT_EQ(s.count, 0);
}

#endif // TEST_SQ_EQ_H

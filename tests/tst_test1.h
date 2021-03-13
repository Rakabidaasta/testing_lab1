#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/* using namespace testing; */
extern "C" {
#include "myfunc.h"
}

TEST(test1, suite1)
{
    EXPECT_EQ(1, 1);
    /*ASSERT_THAT(0, Eq(0)); */
}

TEST(test2, suite1)
{
    EXPECT_EQ(myfunc(0), 4);
}

TEST(test1, suite2)
{
    EXPECT_EQ(myfunc(-1), 3);
}

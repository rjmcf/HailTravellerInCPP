#include "gtest/gtest.h"
#include "sign.h"

TEST(SignTests, itemInheritests)
{
    Sign s0("A sign s0", "test/signTest.txt");

    EXPECT_EQ(s0.getDescription(), "A sign s0");

    EXPECT_TRUE(s0.hasName("sign"));
}

TEST(SignTests, readTest)
{
    Sign s0("A sign s0","test/signTest.txt");

    EXPECT_EQ(s0.read(), "This is a test.\nThis tests line breaks.\n");
}


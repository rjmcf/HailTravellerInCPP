#include "gtest/gtest.h"
#include "sign.h"

TEST(SignTests, itemInheritests)
{
    Sign s0("a sign s0", false, "This text is so cool!");

    EXPECT_EQ(s0.beLookedAt(), "");

    s0.setVisibleTo(true);

    EXPECT_EQ(s0.beLookedAt(), "a sign s0");

    EXPECT_TRUE(s0.hasName("sign"));
}

TEST(SignTests, readTest)
{
    Sign s0("a sign s0", false, "This text is so cool!");

    EXPECT_EQ(s0.read(), "This text is so cool!");
}


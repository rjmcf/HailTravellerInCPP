#include "gtest/gtest.h"
#include "sign.h"

TEST(SignTests, itemInheritests)
{
    Sign s0(false, "A sign s0", "This text is so cool!");

    EXPECT_EQ(s0.getDescription(), "");

    EXPECT_EQ(s0.beLookedAt(), "You can just about read the words on the sign.");

    s0.setVisibleTo(true);

    EXPECT_EQ(s0.getDescription(), "A sign s0");

    EXPECT_TRUE(s0.hasName("sign"));
}

TEST(SignTests, readTest)
{
    Sign s0(false, "A sign s0","This text is so cool!");

    EXPECT_EQ(s0.read(), "This text is so cool!");
}


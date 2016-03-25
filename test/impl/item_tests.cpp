#include "gtest/gtest.h"
#include "item.h"

using std::string;

TEST(ItemTests, constructorGetterTest)
{
	Item i0(true, false, "There is i0", "i0 is beautiful");
	Item i1(false, false, "There is i1", "i1 is beautiful");
	i0.addName("i0");
	i1.addName("i1");

	EXPECT_TRUE(i0.isVisible());
	EXPECT_FALSE(i1.isVisible());
	EXPECT_EQ(i0.getDescription(), "There is i0");
	EXPECT_EQ(i1.getDescription(), "");
	EXPECT_EQ(i0.beLookedAt(), "i0 is beautiful");
	EXPECT_EQ(i1.beLookedAt(), "i1 is beautiful");
	EXPECT_FALSE(i0.isSign());
}

TEST(ItemTests, setVisibilityTest)
{
    Item i0(false, false, "There is i0", "i0 is beautiful");
    i0.addName("i0");

    EXPECT_EQ(i0.getDescription(), "");

    i0.setVisibleTo(true);

    EXPECT_EQ(i0.getDescription(), "There is i0");
}

TEST(ItemTests, hasNameTest)
{
    Item i0(true, false, "There is i0", "i0 is beautiful");
    i0.addName("i0");
    i0.addName("pretty thing");

    EXPECT_TRUE(i0.hasName("i0"));
    EXPECT_TRUE(i0.hasName("pretty thing"));
    EXPECT_FALSE(i0.hasName("i1"));
}

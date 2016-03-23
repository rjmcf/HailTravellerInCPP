#include "gtest/gtest.h"
#include "item.h"

using std::string;

TEST(ItemTests, constructorGetterTest)
{
	Item i0(true, "There is i0", "i0 is beautiful");
	Item i1(false, "There is i1", "i1 is beautiful");
	string n0[] = {"i0"};
	string n1[] = {"i1"};

	i0.setNames(n0,1);
	i1.setNames(n1,1);

	EXPECT_TRUE(i0.isVisible());
	EXPECT_FALSE(i1.isVisible());
	EXPECT_EQ(i0.getDescription(), "There is i0");
	EXPECT_EQ(i1.getDescription(), "");
	EXPECT_EQ(i0.beLookedAt(), "i0 is beautiful");
	EXPECT_EQ(i1.beLookedAt(), "i1 is beautiful");
}

TEST(ItemTests, setVisibilityTest)
{
    Item i0(false, "There is i0", "i0 is beautiful");
    string n0[] = {"i0"};
    i0.setNames(n0, 1);

    EXPECT_EQ(i0.getDescription(), "");

    i0.setVisibleTo(true);

    EXPECT_EQ(i0.getDescription(), "There is i0");
}

TEST(ItemTests, hasNameTest)
{
    Item i0(true, "There is i0", "i0 is beautiful");
    string n0[] = {"i0", "pretty thing"};
    i0.setNames(n0, 2);

    EXPECT_TRUE(i0.hasName("i0"));
    EXPECT_TRUE(i0.hasName("pretty thing"));
    EXPECT_FALSE(i0.hasName("i1"));
}

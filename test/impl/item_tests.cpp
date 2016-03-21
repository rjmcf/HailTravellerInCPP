#include "gtest/gtest.h"
#include "item.h"

TEST(ItemTest, constructorGetterTest)
{
	Item i0("i0 is beautiful", true);
	Item i1("i1 is beautiful", false);
	
	EXPECT_TRUE(i0.isVisible());
	EXPECT_FALSE(i1.isVisible());
	EXPECT_EQ(i0.beLookedAt(), "i0 is beautiful");
	EXPECT_EQ(i1.beLookedAt(), "");
}
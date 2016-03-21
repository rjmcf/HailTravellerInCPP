#include "gtest/gtest.h"
#include "location.h"

TEST(LocationTests, constructorGetterTest)
{
	Location l1("locID1", "This is descriptive");
	
	EXPECT_EQ(l1.getLocID(), "locID1");
	EXPECT_EQ(l1.beLookedAt(), "This is descriptive");
}
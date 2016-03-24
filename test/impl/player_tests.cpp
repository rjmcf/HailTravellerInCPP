#include "gtest/gtest.h"
#include "player.h"

TEST(PlayerTest, setAndGetLocationTests)
{
    Player p;
    Location l0("loc0ID", "l0 is beautiful");
    Location l1("loc1ID", "l1 is beautiful");

    p.setLocation(&l0);
    EXPECT_EQ(p.getLocation()->getLocID(), "loc0ID");

    p.setLocation(&l1);
    EXPECT_EQ(p.getLocation()->getLocID(), "loc1ID");
}

TEST(PlayerTest, movePlayerTest)
{
    Player p;
    Location l0("loc0ID", "l0 is beautiful");
    Location l1("loc1ID", "l1 is beautiful");
    l0.setPath(Direction::F, &l1, "l1");

    p.setLocation(&l0);

    EXPECT_FALSE(p.movePlayer(Direction::B));
    EXPECT_EQ(&l0, p.getLocation());
    EXPECT_TRUE(p.movePlayer(Direction::F));
    EXPECT_EQ(&l1, p.getLocation());
}

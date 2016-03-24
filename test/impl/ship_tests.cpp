#include "gtest/gtest.h"
#include "ship.h"
#include "citPlanet.h"
#include "firePlanet.h"
#include "player.h"

TEST(ShipTests, constructorGetterTest)
{
    Ship s;

    EXPECT_EQ(s.getLocID(), "50");
    EXPECT_EQ(s.beLookedAt(), "The ship has a small cockpit, and you try not to become claustrophobic.\nThere is no path behind you.\n");
}

TEST(ShipTests, landTest)
{
    Ship s;
    Player p;
    CitPlanet c("Citadel");
    FirePlanet f("FirePlanet");

    s.landOn(&c);
    p.setLocation(c.getLocationNum(2));
    ASSERT_TRUE(p.getLocation()->hasPath(Direction::F));

    EXPECT_TRUE(p.movePlayer(Direction::F));
    EXPECT_EQ(p.getLocation()->getLocID(), "50");
    EXPECT_TRUE(p.movePlayer(Direction::B));
    EXPECT_EQ(p.getLocation()->getLocID(), "02");

    p.movePlayer(Direction::F);
    s.landOn(&f);
    EXPECT_TRUE(p.movePlayer(Direction::B));
    EXPECT_EQ(p.getLocation()->getLocID(), "10");
    EXPECT_TRUE(p.movePlayer(Direction::B));
    EXPECT_EQ(p.getLocation()->getLocID(), "50");
}

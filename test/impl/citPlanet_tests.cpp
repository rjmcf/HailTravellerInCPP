#include "gtest/gtest.h"
#include "citPlanet.h"
#include "player.h"
#include "ship.h"

TEST(CitPlanetTests, minimalConstructorTest)
{
    CitPlanet c("Citadel");

    EXPECT_EQ(c.getName(), "Citadel");
    EXPECT_EQ((c.getLocationNum(0))->getLocID(), "00");
    EXPECT_EQ(c.getLocationNum(0)->beLookedAt(), "You are surrounded by tumble-down houses. You assume a village might once have stood here.\nRows of houses spilling their guts on to the road surround you.\nA wooden sign is sticking upright in the dusty ground.\nThere is no path in front of you.\nTo your left there is a path leading deeper in to the village between the houses.\nThere is no path to your right.\nThere is no path behind you.\n");
    EXPECT_EQ(c.getLandingLocation()->getLocID(), "02");
    EXPECT_EQ(c.getShipDirection(), Direction::F);
    EXPECT_EQ(c.getShipPathD(), "the spaceship, lying as you first found it.");
}

TEST(CitPlanetTests, movePlayerTest)
{
    Player p;
    Ship s;
    CitPlanet c("Citadel");
    p.setLocation(c.getLocationNum(0));
    s.landOn(&c);

    EXPECT_FALSE(p.movePlayer(Direction::R));
    ASSERT_TRUE(p.movePlayer(Direction::L));
    EXPECT_EQ((p.getLocation())->getLocID(), "01");
    EXPECT_FALSE(p.movePlayer(Direction::L));
    ASSERT_TRUE(p.movePlayer(Direction::R));
    EXPECT_EQ((p.getLocation())->getLocID(), "00");

    p.setLocation(c.getLocationNum(2));

    EXPECT_TRUE(p.movePlayer(Direction::F));
    EXPECT_TRUE(p.movePlayer(Direction::B));
    EXPECT_TRUE(p.movePlayer(Direction::L));
    EXPECT_EQ((p.getLocation())->getLocID(), "00");

}

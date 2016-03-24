#include "gtest/gtest.h"
#include "firePlanet.h"
#include "player.h"
#include "ship.h"

TEST(FirePlanetTests, minimalConstructorTests)
{
    FirePlanet f("Paxak");

    EXPECT_EQ(f.getName(), "Paxak");
    EXPECT_EQ(f.getLocationNum(0)->getLocID(), "10");
    EXPECT_EQ(f.getLocationNum(0)->beLookedAt(), "The spaceship sits behind you, hanging on the edge of a large crater, which glows mysteriously due to the magma inside.\nThe spaceship is still there, thank goodness.\nThe crater behind the spaceship glows ominously.\nA metal board attached to a section of small girder protrudes from the ground. You guess that this is the Paxak version of signs.\nThere is no path in front of you.\nTo your left there is a rocky path leading towards a large smoking vlcano in the distance.\nThere is no path to your right.\nThere is no path behind you.\n");
    EXPECT_EQ(f.getLandingLocation()->getLocID(), "10");
    EXPECT_EQ(f.getShipDirection(), Direction::B);
    EXPECT_EQ(f.getShipPathD(), "the spaceship, looking invitingly cool compared to the temperature out here.");
}


TEST(FirePlanetTests, moveTest)
{
    Player p;
    Ship s;
    FirePlanet f("Paxak");
    p.setLocation(f.getLocationNum(0));
    s.landOn(&f);

    EXPECT_TRUE(p.movePlayer(Direction::B));
    EXPECT_TRUE(p.movePlayer(Direction::B));
    EXPECT_FALSE(p.movePlayer(Direction::R));
    EXPECT_FALSE(p.movePlayer(Direction::F));
    EXPECT_TRUE(p.movePlayer(Direction::L));
    EXPECT_TRUE(p.movePlayer(Direction::F));
    EXPECT_TRUE(p.movePlayer(Direction::R));
    EXPECT_TRUE(p.movePlayer(Direction::R));
    EXPECT_TRUE(p.movePlayer(Direction::B));
    EXPECT_TRUE(p.movePlayer(Direction::L));

    EXPECT_EQ((p.getLocation())->getLocID(), "10");

    p.setLocation(f.getLocationNum(3));
    EXPECT_TRUE(p.movePlayer(Direction::B));
    EXPECT_EQ((p.getLocation())->getLocID(), "10");

}

#include "gtest/gtest.h"
#include "citPlanet.h"

#include <iostream>

TEST(CitPlanetTests, minimalConstructorTest)
{
    CitPlanet c("Citadel");

    EXPECT_EQ(c.getName(), "Citadel");
    EXPECT_EQ((c.getLocationNum(0))->getLocID(), "00");
    EXPECT_EQ(c.getLocationNum(0), c.getCurrentLocation());
    EXPECT_EQ((c.getCurrentLocation())->beLookedAt(), "You are surrounded by tumble-down houses. You assume a village might once have stood here.\nRows of houses spilling their guts on to the road surround you.\nA wooden sign is sticking upright in the dusty ground.\nThere is no path in front of you.\nThere is no path to your left.\nThere is no path to your right.\nThere is no path behind you.\n");
}

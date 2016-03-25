#include "gtest/gtest.h"
#include "executer.h"

TEST(ExecuterTests, constructerTest)
{
    Executer e;

    EXPECT_EQ(e.getPlayer()->getLocation(), e.getShip()->getCurrentPlanet()->getLocationNum(0));
}

TEST(ExecuterTests, errorTest)
{
    Executer e;

    EXPECT_EQ(e.executeCommand(""), "You can't do that!\n");
}

TEST(ExecuterTests, readTest)
{
    Executer e;

    EXPECT_EQ(e.executeCommand("read"), "You read the sign.\n\nThis is the text on the first sign.\n");
}

TEST(ExecuterTests, lookTest)
{
    Executer e;

    EXPECT_EQ(e.executeCommand("look"), "You are surrounded by tumble-down houses. You assume a village might once have stood here.\nRows of houses spilling their guts on to the road surround you.\nA wooden sign is sticking upright in the dusty ground.\nThere is no path in front of you.\nTo your left there is a path leading deeper in to the village between the houses.\nThere is no path to your right.\nThere is no path behind you.\n");

}

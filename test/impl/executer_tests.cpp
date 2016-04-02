#include "gtest/gtest.h"
#include "executer.h"

TEST(ExecuterTests, constructerTest)
{
    Executer e;

    EXPECT_EQ(e.getPlayer()->getLocation(), e.getShip()->getCurrentPlanet()->getLocationNum(0));
}


#include "gtest/gtest.h"
#include "planet.h"

TEST(PlanetTest, constructorGetterTest)
{
    Planet p0("P0");

    EXPECT_EQ(p0.getName(), "P0");
}

TEST(PlanetTest, locationVectorTest)
{
    Planet p0("P0");

    Location *l0 = new Location("l0", "Dl0");
    Location *l1 = new Location("l1", "Dl1");

    p0.addLocation(l0);
    p0.addLocation(l1);

    EXPECT_EQ(p0.DEBUGgetLocations(), "l0\nl1\n");
}

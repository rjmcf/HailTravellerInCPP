#include "gtest/gtest.h"
#include "planet.h"

class PlanetTest : public testing::Test
{
    protected:
        virtual void SetUp()
        {
            p0 = new Planet("P0");
            l0 = new Location("l0", "Dl0");
            l1 = new Location("l1", "Dl1");

            l0->setForwards(l1, "PDl1");

            p0->addLocation(l0);
            p0->addLocation(l1);

            p0->setCurrentLocation(0);
        }

        virtual void TearDown()
        {
            delete p0;
            delete l0;
            delete l1;
        }

        Planet *p0;
        Location *l0, *l1;
};

TEST_F(PlanetTest, constructorGetterTest)
{
    EXPECT_EQ(p0->getName(), "P0");
}

TEST_F(PlanetTest, locationVectorTest)
{
    EXPECT_EQ((p0->getLocationNum(0))->getLocID(), "l0");
    EXPECT_EQ((p0->getLocationNum(1))->getLocID(), "l1");
}

TEST_F(PlanetTest, currentLocationTest)
{
    EXPECT_EQ(p0->getLocationNum(0), p0->getCurrentLocation());
}

TEST_F(PlanetTest, movePlayerTest)
{
    EXPECT_FALSE(p0->movePlayer(Direction::B));
    EXPECT_EQ(p0->getLocationNum(0), p0->getCurrentLocation());
    EXPECT_TRUE(p0->movePlayer(Direction::F));
    EXPECT_EQ(p0->getLocationNum(1), p0->getCurrentLocation());
}

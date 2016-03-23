#include "citPlanet.h"

CitPlanet::CitPlanet(string name) : Planet(name)
{
    game_begin = new Location("00", "You are surrounded by tumble-down houses. You assume a village might once have stood here.");
    houses = new Item(true, "Rows of houses spilling their guts on to the road surround you.", "The houses look like they have been destroyed by a large explosion. You wonder who lived there, and how they must have died.");
    sign1 = new Sign(true, "A wooden sign is sticking upright in the dusty ground.", "This is the text on the sign.");
    game_begin->addItem(houses);
    game_begin->addItem(sign1);

    addLocation(game_begin);
    setCurrentLocation(0);
}

CitPlanet::~CitPlanet()
{
    delete game_begin;
    delete houses;
    delete sign1;
}

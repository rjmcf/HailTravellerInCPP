#include "citPlanet.h"

CitPlanet::CitPlanet(string name) : Planet(name, Direction::F, "the spaceship, lying as you first found it.")
{
    game_begin = new Location("00", "You are surrounded by tumble-down houses. You assume a village might once have stood here.");
    houses = new Item(true, "Rows of houses spilling their guts on to the road surround you.", "The houses look like they have been destroyed by a large explosion. You wonder who lived there, and how they must have died.");
    houses->addName("houses"); houses->addName("house"); houses->addName("buildings");
    sign1 = new Sign("A wooden sign is sticking upright in the dusty ground.", "src/signs/citPlanet/sign1.txt");
    game_begin->addItem(houses); game_begin->addItem(sign1);

    second_sign = new Location("01", "In front of you is a giant building, towers and flying buttresses everywhere. The door is barred.");
    cit = new Item(true, "There is a large building that looks like it might be a citadel of some sort.", "The imposing building looks like it would be difficult to attack and easy to defend. You wouldn't mind living inside it during a seige.");
    cit->addName("citadel"); cit->addName("building");
    sign2 = new Sign("A sign is hanging from the door of the citadel.", "src/signs/citPlanet/sign2.txt");
    second_sign->addItem(cit); second_sign->addItem(sign2);

    ship_hidden = new Location("02", "You are standing in front of a spaceship.");
    ship_item = new Item(true, "A spaceship rests lopsidedly in the dirt.", "The spaceship looks in a much worse state than it actually is. You hope.");
    ship_item->addName("ship"); ship_item->addName("spaceship"); ship_item->addName("spacecraft");
    ship_hidden->addItem(ship_item);

    addLocation(game_begin);
    addLocation(second_sign);
    addLocation(ship_hidden);
    setLandingLocation(2);

    game_begin->setPath(Direction::L, second_sign, "a path leading deeper in to the village between the houses.");
    second_sign->setPath(Direction::R, game_begin, "a path that will take you back to where you woke up.");
    ship_hidden->setPath(Direction::L, game_begin, "the path through the trees leading back to the village.");
}

CitPlanet::~CitPlanet()
{
    delete game_begin;
    delete houses;
    delete sign1;
    delete second_sign;
    delete cit;
    delete sign2;
    delete ship_hidden;
    delete ship_item;
}

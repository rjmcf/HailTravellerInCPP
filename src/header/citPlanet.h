#ifndef CITPLANET_H_INCLUDED
#define CITPLANET_H_INCLUDED

#include "planet.h"
#include "location.h"
#include "item.h"
#include "sign.h"

class CitPlanet : public Planet
{
    private:
        Location *game_begin, *second_sign, *ship_hidden;
        Item *houses, *cit, *ship_item;
        Sign *sign1, *sign2;

    public:
        CitPlanet(string);
        ~CitPlanet();
        Location *getStartingLocation() { return game_begin; }
};



#endif // CITPLANET_H_INCLUDED

#ifndef FIREPLANET_H_INCLUDED
#define FIREPLANET_H_INCLUDED

#include "planet.h"
#include "location.h"
#include "item.h"
#include "sign.h"

class FirePlanet : public Planet
{
    private:
        Location *crater, *volcano_base, *mine, *village, *lava_pool, *workshop;
        Item *ship_item, *crater_item, *volcano, *mine_item, *buildings, *pool, *forge;
        Sign *sign1, *sign2, *sign3, *sign4, *sign5, *sign6;
    public:
        FirePlanet(string);
        ~FirePlanet();

};



#endif // FIREPLANET_H_INCLUDED

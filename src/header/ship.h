#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include "location.h"
#include "planet.h"

class Ship : public Location
{
    private:
        Planet *currentPlanet;
    public:
        Ship() : Location("50", "The ship has a small cockpit, and you try not to become claustrophobic."), currentPlanet(0) { }
        ~Ship() { }
        Planet *getCurrentPlanet() { return currentPlanet; }
        void setCurrentPlanet(Planet *p) { currentPlanet = p; }
        void landOn(Planet *p);
};





#endif // SHIP_H_INCLUDED

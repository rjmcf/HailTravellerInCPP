#include "ship.h"

void Ship::landOn(Planet *p)
{
    setCurrentPlanet(p);
    getCurrentPlanet()->getLandingLocation()->setPath(getCurrentPlanet()->getShipDirection(), this, getCurrentPlanet()->getShipPathD());
    string path = "the door that leads out onto " + getCurrentPlanet()->getName();
    setPath(Direction::B, getCurrentPlanet()->getLandingLocation(), path);
}

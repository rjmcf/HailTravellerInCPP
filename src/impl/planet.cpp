#include <iostream>
#include "planet.h"
#include "direction.h"

bool Planet::movePlayer(DirectionT d)
{
    if (current_location->hasPath(d))
    {
        current_location = current_location->getPath(d);
        return true;
    }

    return false;
}

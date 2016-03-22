#include <iostream>
#include "planet.h"

string Planet::DEBUGgetLocations()
{
    string result = "";
    for (Location* l : locations)
    {
        result += l->getLocID() + "\n";
    }

    return result;
}

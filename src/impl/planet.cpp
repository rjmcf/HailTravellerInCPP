#include <iostream>
#include "planet.h"

string Planet::DEBUGgetLocations()
{
    string result = "";
    for (unsigned int i = 0; i < locations.size(); i++)
    {
        result += (locations.at(i))->getLocID() + "\n";
    }

    return result;
}

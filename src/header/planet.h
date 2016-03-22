#ifndef PLANET_H_INCLUDED
#define PLANET_H_INCLUDED

#include <vector>
#include <string>
#include "location.h"

using std::vector;
using std::string;

class Planet
{
    private:
        string name;
        vector<Location*> locations;
    public:
        Planet(string n) : name(n), locations(0) { }
        ~Planet() { }
        string getName() { return name; }
        void addLocation(Location *l) { locations.push_back(l); }
        string DEBUGgetLocations();
};


#endif // PLANET_H_INCLUDED

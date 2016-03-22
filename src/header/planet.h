#ifndef PLANET_H_INCLUDED
#define PLANET_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "location.h"
#include "direction.h"

using std::vector;
using std::string;

class Planet
{
    protected:
        string name;
        vector<Location*> locations;
        Location *current_location;
    public:
        Planet(string n) : name(n), locations(0), current_location(0) { }
        virtual ~Planet() { }
        string getName() const { return name; }
        void addLocation(Location *l) { locations.push_back(l); }
        Location *getLocationNum(int n) const { return locations.at(n); }
        void setCurrentLocation(int n) { current_location = locations.at(n); }
        Location *getCurrentLocation() const { return current_location; }
        virtual bool movePlayer(DirectionT);
};


#endif // PLANET_H_INCLUDED

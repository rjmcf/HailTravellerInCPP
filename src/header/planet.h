#ifndef PLANET_H_INCLUDED
#define PLANET_H_INCLUDED

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
        Location *landing_location;
        DirectionT ship_direction;
        string ship_path_d;
    public:
        Planet(string n, DirectionT d, string sd) : name(n), locations(0), landing_location(0), ship_direction(d), ship_path_d(sd) { }
        virtual ~Planet() { }
        string getName() const { return name; }
        DirectionT getShipDirection() { return ship_direction; }
        string getShipPathD() { return ship_path_d; }
        void addLocation(Location *l) { locations.push_back(l); }
        Location *getLocationNum(int n) const { return locations.at(n); }
        void setLandingLocation(int n) { landing_location = locations.at(n); }
        Location *getLandingLocation() const { return landing_location; }
};


#endif // PLANET_H_INCLUDED

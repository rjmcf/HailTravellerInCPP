#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "location.h"
#include "direction.h"

class Player
{
    private:
        Location* current_location;
    public:
        Player() : current_location(0) { }
        ~Player() { }
        void setLocation(Location* l) { current_location = l; }
        Location *getLocation() { return current_location; }
        bool movePlayer(DirectionT);
};



#endif // PLAYER_H_INCLUDED

#ifndef EXECUTER_H_INCLUDED
#define EXECUTER_H_INCLUDED

#include "player.h"
#include "ship.h"
#include "citPlanet.h"
#include "firePlanet.h"

class Executer
{
    private:
        string toPrint;
        Player *player;
        Ship *ship;
        CitPlanet *citP;
        FirePlanet *fireP;
        string doRead();
        string doLook();
        string raiseError() { return "You can't do that!"; }
    public:
        Executer();
        ~Executer();
        Player *getPlayer() { return player; }
        Ship *getShip() { return ship; }
        string executeCommand(string);
};



#endif // EXECUTER_H_INCLUDED

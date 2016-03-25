#ifndef EXECUTER_H_INCLUDED
#define EXECUTER_H_INCLUDED

#include <iostream>
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
    public:
        Executer();
        ~Executer();
        Player *getPlayer() { return player; }
        Ship *getShip() { return ship; }
        void printString(string s) { std::cout << s << std::endl; }
        string executeCommand(string);
};



#endif // EXECUTER_H_INCLUDED

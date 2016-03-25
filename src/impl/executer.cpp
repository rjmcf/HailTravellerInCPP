#include "executer.h"

Executer::Executer() : toPrint("")
{
    player = new Player();
    ship = new Ship();
    citP = new CitPlanet("Citadel");
    fireP = new FirePlanet("Paxak");

    ship->landOn(citP);
    player->setLocation(citP->getStartingLocation());
}

Executer::~Executer()
{
    delete player;
    delete ship;
    delete citP;
    delete fireP;
}

string Executer::executeCommand(string command)
{
    if (command.string::find("read") != string::npos)
    {
        return doRead();
    }
    else if (command.string::find("look") != string::npos)
    {
        return doLook();
    }
    else
    {
        return "You can't do that!\n";
    }
}

string Executer::doRead()
{
    if (player->getLocation()->hasSign())
    {
        Sign* sign = player->getLocation()->getSign();
        toPrint = "You read the sign.\n\n";
        toPrint += sign->read() + "\n";
    }
    else toPrint = "There is nothing to read!";

    return toPrint;
}

string Executer::doLook()
{
    return player->getLocation()->beLookedAt();
}

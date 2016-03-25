#include "location.h"
#include "direction.h"

string Location::beLookedAt() const
{
    string result = description + "\n";
    for (unsigned int i = 0; i < items.size() ; i++)
    {
        if ((items.at(i))->isVisible())
        {
            result += (items.at(i))->getDescription() + "\n";
        }
    }
    if (forwards == nullptr && loc_id != "50") result += "There is no path in front of you.\n";
    else if(loc_id != "50") result += "In front of you there is " + fPath + "\n";

    if (left == nullptr && loc_id != "50") result += "There is no path to your left.\n";
    else if(loc_id != "50") result += "To your left there is " + lPath + "\n";

    if (right == nullptr && loc_id != "50") result += "There is no path to your right.\n";
    else if(loc_id != "50") result += "To your right there is " + rPath + "\n";

    if (backwards == nullptr) result += "There is no path behind you.\n";
    else result += "Behind you there is " + bPath + "\n";

    return result;
}

bool Location::hasPath(DirectionT d)
{
    return *(directionToLocation(d))!=nullptr;
}

Location *Location::getPath(DirectionT d) const
{
    switch (d)
    {
    case Direction::F:
        return forwards;
    case Direction::L:
        return left;
    case Direction::R:
        return right;
    default:
        return backwards;
    }
}

Location **Location::directionToLocation(DirectionT d)
{
    switch (d)
    {
    case Direction::F:
        return &forwards;
    case Direction::L:
        return &left;
    case Direction::R:
        return &right;
    default:
        return &backwards;
    }
}

string *Location::directionToPathD(DirectionT d)
{
    switch (d)
    {
    case Direction::F:
        return &fPath;
    case Direction::L:
        return &lPath;
    case Direction::R:
        return &rPath;
    default:
        return &bPath;
    }
}

void Location::setPath(DirectionT d, Location *l, string p)
{
    Location **lToChange = directionToLocation(d);
    string *pToChange = directionToPathD(d);
    *lToChange = l;
    *pToChange = p;
}

void Location::removePath(DirectionT d)
{
    Location **toRemove = directionToLocation(d);
    *toRemove = 0;
}

bool Location::hasSign() const
{
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (items.at(i)->isSign()) return true;
    }
    return false;
}

Sign *Location::getSign() const
{
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (items.at(i)->isSign()) return static_cast<Sign*>(items.at(i));
    }
    return nullptr;
}


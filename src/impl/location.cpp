#include <iostream>
#include<string>
#include<vector>
#include "location.h"
#include "item.h"
#include "direction.h"

string Location::beLookedAt() const
{
    string result = description + "\n";
    for (unsigned int i = 0; i < items.size() ; i++)
    {
        if ((items.at(i))->isVisible())
        {
            result += (items.at(i))->beLookedAt() + "\n";
        }
    }
    if (forwards == 0) result += "There is no path in front of you\n";
    else result += "In front of you there is " + fPath + "\n";

    if (left == 0) result += "There is no path to your left\n";
    else result += "To your left there is " + lPath + "\n";

    if (right == 0) result += "There is no path to your right\n";
    else result += "To your right there is " + rPath + "\n";

    if (backwards == 0) result += "There is no path behind you\n";
    else result += "Behind you there is " + bPath + "\n";

    return result;
}

bool Location::hasPath(DirectionT d) const
{
    return getPath(d)!=0;
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


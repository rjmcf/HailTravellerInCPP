#include "item.h"

string Item::getDescription() const
{
	if (visible) return description;
	else return "";
}

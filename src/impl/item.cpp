#include "item.h"

string Item::beLookedAt()
{
	if (visible) return description;
	else return "";
}
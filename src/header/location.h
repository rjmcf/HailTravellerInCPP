#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED

#include <vector>
#include <string>
#include "item.h"
#include "direction.h"

using std::string;
using std::vector;

class Location
{
	private:
		const string loc_id;
		string description;
		vector<Item*> items;
		Location *forwards;
		string fPath;
		Location *left;
		string lPath;
		Location *right;
		string rPath;
		Location *backwards;
		string bPath;
	public:
		Location(string lID, string d) : loc_id(lID), description(d), items(0), forwards(0), left(0), right(0), backwards(0) { }
		~Location() { }
		const string getLocID() const { return loc_id; }
		string beLookedAt() const;
		void addItem(Item * const i) { items.push_back(i); }
		void setForwards(Location *f, string fP) { forwards = f; fPath = fP; }
		void setLeft(Location *l, string lP) { left = l; lPath = lP; }
		void setRight(Location *r, string rP) { right = r; rPath = rP; }
		void setBackwards(Location *b, string bP) { backwards = b; bPath = bP; }
		bool hasPath(DirectionT) const;
		Location *getPath(DirectionT) const;
};

#endif // LOCATION_H_INCLUDED

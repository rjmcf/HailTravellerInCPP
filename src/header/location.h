#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED

#include <vector>
#include <string>
#include "item.h"
#include "sign.h"
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
		Location **directionToLocation(DirectionT);
		string *directionToPathD(DirectionT);
	public:
		Location(string lID, string d) : loc_id(lID), description(d), forwards(nullptr), left(nullptr), right(nullptr), backwards(nullptr) { }
		~Location() { }
		const string getLocID() const { return loc_id; }
		string beLookedAt() const;
		void addItem(Item * const i) { items.push_back(i); }
		Location *getPath(DirectionT) const;
		void setPath(DirectionT, Location *, string);
		void removePath(DirectionT);
		bool hasPath(DirectionT);
		bool hasSign() const;
		Sign* getSign() const;
};

#endif // LOCATION_H_INCLUDED

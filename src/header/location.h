#include <string>
#include <iostream>

using std::string;

class Location
{
	private:
		const string loc_id;
		string description;
	public:
		Location(string lID, string d) : loc_id(lID), description(d) { }
		~Location() { }
		const string getLocID() { return loc_id; }
		string beLookedAt() { return description; }
};
	
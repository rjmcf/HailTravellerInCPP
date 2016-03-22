#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include<string>
#include<set>

using std::string;
using std::set;

class Item
{
	private:
		string description;
		bool visible;
		set<string> names;
	public:
		Item(string d, bool is_v) : description(d), visible(is_v) { }
		~Item() { }
		bool isVisible() { return visible; }
		void setNames(string [], int);
		bool hasName(string n) { return names.find(n) != names.end(); }
		void setVisibleTo(bool v) { visible = v; }
		string beLookedAt();
};

#endif // ITEM_H_INCLUDED

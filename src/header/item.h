#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include<string>
#include<set>

using std::string;
using std::set;

class Item
{
	protected:
		string description;
		bool visible;
		set<string> names;
	public:
		Item(string d, bool is_v) : description(d), visible(is_v) { }
		~Item() { }
		/* necessary for object consistency */
		void setNames(string [], int);
		bool isVisible() const { return visible; }
		bool hasName(string n) const { return names.find(n) != names.end(); }
		void setVisibleTo(bool v) { visible = v; }
		string beLookedAt() const;
};

#endif // ITEM_H_INCLUDED

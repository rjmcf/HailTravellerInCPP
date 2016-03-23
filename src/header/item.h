#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include<string>
#include<set>

using std::string;
using std::set;

class Item
{
	protected:
	    bool visible;
		string description;
		string look_description;
		set<string> names;
	public:
		Item(bool is_v, string d, string ld) : visible(is_v), description(d), look_description(ld) { }
		~Item() { }
		/* necessary for object consistency */
		void setNames(string [], int);
		bool isVisible() const { return visible; }
		bool hasName(string n) const { return names.find(n) != names.end(); }
		void setVisibleTo(bool v) { visible = v; }
		string getDescription() const;
		string beLookedAt() const { return look_description; }
};

#endif // ITEM_H_INCLUDED

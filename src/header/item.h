#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <string>
#include <set>

using std::string;
using std::set;

class Item
{
	protected:
	    bool visible;
	    bool is_sign;
		string description;
		string look_description;
		set<string> names;
	public:
		Item(bool is_v, bool is_s, string d, string ld) : visible(is_v), is_sign(is_s), description(d), look_description(ld) { }
		virtual ~Item() { }
		/* necessary for object consistency */
		void addName(string n) { names.insert(n); }
		bool isVisible() const { return visible; }
		bool isSign() const { return is_sign; }
		bool hasName(string n) const { return names.find(n) != names.end(); }
		void setVisibleTo(bool v) { visible = v; }
		virtual string getDescription() const;
		string beLookedAt() const { return look_description; }
};

#endif // ITEM_H_INCLUDED

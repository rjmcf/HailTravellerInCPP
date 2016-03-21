#include <string>

using std::string;

class Item
{
	private:
		string description;
		bool visible;
	public:
		Item(string d, bool is_v) : description(d), visible(is_v) { }
		~Item() { }
		bool isVisible() { return visible; }
		string beLookedAt();
};
	
#ifndef SIGN_H_INCLUDED
#define SIGN_H_INCLUDED

#include <string>
#include "item.h"

using std::string;

class Sign : public Item
{
    private:
        string text;
    public:
        Sign(bool is_v, string d, string t) : Item(is_v, d, "You can just about read the words on the sign."), text(t) { string names[] = {"sign"}; setNames(names, 1); }
        ~Sign() { }
        string read() { return text; }
};



#endif // SIGN_H_INCLUDED

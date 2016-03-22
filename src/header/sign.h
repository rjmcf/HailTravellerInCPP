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
        Sign(string d, bool is_v, string t) : Item(d, is_v), text(t) { string names[] = {"sign"}; setNames(names, 1); }
        ~Sign() { }
        string read() { return text; }
};



#endif // SIGN_H_INCLUDED

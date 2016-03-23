#ifndef SIGN_H_INCLUDED
#define SIGN_H_INCLUDED

#include <iostream>
#include <string>
#include "item.h"

using std::string;

class Sign : public Item
{
    private:
        string text;
    public:
        Sign(string d, string t) : Item(true, d, "You can just about read the words on the sign."), text(t) { addName("sign"); }
        ~Sign() { }
        string read() { return text; }
};



#endif // SIGN_H_INCLUDED

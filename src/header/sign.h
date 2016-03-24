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
        Sign(string, string);
        ~Sign() { }
        string read() { return text; }
};



#endif // SIGN_H_INCLUDED

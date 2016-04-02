#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#include <iostream>
#include "parser.h"

class Core
{
    private:
        Parser *parser;
    public:
        Core() { }
        ~Core() { }
        string getInput() { return ""; } //TODO implement
        string getCommandResponse(string) { return ""; } // TODO implement
        void printOutput(string s) { std::cout << s << std::endl; }
};



#endif // CORE_H_INCLUDED

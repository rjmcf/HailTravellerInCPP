#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <string>
#include <set>

using std::string;
using std::set;

struct Tokens
{
    string verb;
    string noun;
    Tokens() : verb(""), noun("") { }
    Tokens(string v, string n) : verb(v), noun(n) { }
};

class TwoVerbsException {};
class TwoNounsException {};

class Parser
{
    private:
        set<string> verbs;
        set<string> nouns;
        bool isVerb(string v) { return verbs.find(v) != verbs.end(); }
        bool isNoun(string n) { return nouns.find(n) != nouns.end(); }
    public:
        Parser() { }
        ~Parser() { }
        Tokens getTokens(string);
        void addVerb(string v) { verbs.insert(v); }
        void addNoun(string n) { nouns.insert(n); }
        void clearNouns() { nouns.clear(); }
};

#endif // PARSER_H_INCLUDED

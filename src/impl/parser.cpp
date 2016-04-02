#include "parser.h"

#include <iostream>

Tokens Parser::getTokens(string s)
{
    string delims = " .,?!";

    set<string> words;

    string word = "";

    for (unsigned int i = 0; i < s.size(); i++)
    {
        if (delims.find(s[i]) != string::npos )
        {
            if (word != "")
            {
                words.insert(word);
                word = "";
            }
        }
        else
        {
            word += s[i];
        }
    }

    if (word != "")
    {
        words.insert(word);
    }

    Tokens t;
    set<string>::iterator it;

    for (it = words.begin(); it != words.end(); it++)
    {
        if (isVerb(*it))
        {
            if (t.verb == "")
                t.verb = *it;
            else //ERROR
            {
                TwoVerbsException e;
                throw e;
            }
        }
        else if (isNoun(*it))
        {
            if (t.noun == "")
                t.noun = *it;
            else //ERROR
            {
                TwoNounsException e;
                throw e;
            }
        }
    }

    return t;
}

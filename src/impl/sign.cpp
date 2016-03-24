#include <iostream>
#include <fstream>
#include "sign.h"

Sign::Sign(string d, string f) : Item(true, d, "You can just about read the words on the sign.")
{
    addName("sign");
    string temp;
    string line;

    std::ifstream file(f);
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            temp += line + "\n";
        }
        text = temp;
        file.close();
    }
    else
    {
        std::cout << "There was a problem openeing the file" << std::endl;
    }

}

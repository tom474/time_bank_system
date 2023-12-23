#ifndef _MENU_OPTIONS_GENERATOR_H
#define _MENU_OPTIONS_GENERATOR_H

#include <string>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class MenuOptionsGenerator
{
public:
    static void showMenu(vector<string> options);
};

#endif
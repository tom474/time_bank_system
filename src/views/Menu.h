#ifndef _MENU_H_
#define _MENU_H_

// #include "function.h"

#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Menu
{
public:
    string currentScreen;

    // declarations of constructors/methods
    Menu();
    void printMenu();
};

#endif

#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Menu
{
public:
    string currentScreen;

    Menu();
    void showWelcome();
};

#endif

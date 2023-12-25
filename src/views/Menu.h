#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <string>
#include <array>
using std::cout;
using std::endl;
using std::string;

class Menu {
public:
    string currentScreen;

    Menu();
    static void showWelcome();
    static void loginAsGuest();
    static void loginAsMember();
    static void loginAsAdmin();
};

#endif

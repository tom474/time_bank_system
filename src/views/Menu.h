#ifndef _MENU_H_
#define _MENU_H_

#include "GuestController.h"
#include "MenuOptionsGenerator.h"
#include "MemberController.h"
#include "AdminController.h"
#include "../models/user/Member.h"
#include "../utils/FileManager.h"

#include <iostream>
#include <string>
#include <array>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Menu {
public:
    string currentScreen;
    static vector<Member*> allMembers;
    Menu();
    static void showWelcome();
    static void loginAsGuest();
    static void loginAsMember();
    static void loginAsAdmin();
};

#endif

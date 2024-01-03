#ifndef _MENU_H_
#define _MENU_H_

#include "../controllers/GuestController.h"
#include "../utils/MenuOptionsGenerator.h"
#include "../controllers/MemberController.h"
#include "../controllers/AdminController.h"
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
    static Member loggedInMember;
    Menu();
    static void showWelcome();
    static void loginAsGuest();
    static void loginAsMember();
    static void loginAsAdmin();
};

#endif

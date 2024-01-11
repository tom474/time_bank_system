#ifndef _MENU_H_
#define _MENU_H_

#include "../controllers/GuestController.h"
#include "../utils/MenuOptionsGenerator.h"
#include "../controllers/MemberController.h"
#include "../controllers/AdminController.h"
#include "../models/user/Member.h"
#include "../utils/FileManager.h"
#include "../utils/TableGenerator.h"

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

        /**
         * The constructor for the Menu class
        */
        Menu();

        /**
         * The function to show the welcome screen
         *
         * @param none
         * @return none
        */
        static void showWelcome();

        /**
         * The function to show the guest menu
         *
         * @param none
         * @return none
        */
        static void loginAsGuest();

        /**
         * The function to show the member menu after member login successfully
         *
         * @param none
         * @return none
        */
        static void loginAsMember();

        /**
         * The function to show the admin menu after admin login successfully
         *
         * @param none
         * @return none
        */
        static void loginAsAdmin();
};

#endif // _MENU_H_

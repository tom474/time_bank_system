#include <iostream>
#include "Menu.h"

#define GUEST = 1
#define MEMBER = 1
#define ADMIN = 1

// TODO: currentScreen attribute for rendering messages
Menu::Menu() { this->currentScreen = "Welcome"; }

vector<Member*> Menu::allMembers = FileManager::loadMemberDatabase(); 

void Menu::showWelcome() {
    cout << "EEET2482/COSC2082 ASSIGNMENT \n"
         << "''TIME BANK'' APPLICATION \n\n"
         << "Instructor : Mr.Tran Duc Linh \n"
         << "Group: Group No.11 \n"
         << "s3804811, Pham Quang Man \n"
         << "s3804811, Pham Quang Man \n"
         << "s3804811, Pham Quang Man \n"
         << "s3804811, Pham Quang Man \n\n";
    int choice = MenuOptionsGenerator::showMenuWithSelect("Use the app as:", {"Guest", "Member", "Admin"});
    bool exit = false;
    do {
        switch (choice) {
        case 1:
            loginAsGuest();
            exit = true;
            break;

        case 2:
            loginAsMember();
            exit = true;
            break;
        case 3:
            loginAsAdmin();
            exit = true;
            break;

            // Invalid Option
        default:
            choice = InputValidator::getInt("Invalid option. Please enter the correct login option (1-3): ");
            break;
        }

    } while (!exit); // Exit while loop after correct choice is selected
}

void Menu::loginAsGuest() {
    cout << "---------- Guest Menu ----------\n";
    int choice = MenuOptionsGenerator::showMenuWithSelect(
        "Choose an action: ",
        {"Exit",
         "Sign up",
         "View supporter details"});
    switch (choice) {
    case 0:
        break;
    case 1:
        GuestController::signUp();
        break;
    case 2:
        cout << "Viewing supporter details";
        break;

    default:
        break;
    }
}

void Menu::loginAsMember() {
    // cout << "Logging in as Member" << endl;
    Member* currentMember = MemberController::login();
    if (currentMember == nullptr) {
        return;
    }
    cout << "---------- Member Menu ----------\n";
    MenuOptionsGenerator::showMenuWithSelect(
        "Choose an action: ",
        {"Exit",
            "View your information",
            "Manage your requests",
            "Set your availability",
            "Search for supporters",
            "Rate your host/supporter",
            "Unblock/Block member"});
    
}

void Menu::loginAsAdmin() {
    if (AdminController::login()) {
        cout << "---------- Admin Menu ----------\n";
        MenuOptionsGenerator::showMenuWithSelect("Choose an action:", {"Exit", "Reset password for member"});
    }
}
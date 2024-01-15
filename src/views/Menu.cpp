#include "Menu.h"

#include <iostream>

#define GUEST = 1
#define MEMBER = 1
#define ADMIN = 1

// TODO: currentScreen attribute for rendering messages
Menu::Menu() { this->currentScreen = "Welcome"; }

vector<Member *> Menu::allMembers = FileManager::loadMemberDatabase();

void Menu::showWelcome() {
    cout << "\nEEET2482/COSC2082 ASSIGNMENT\n"
         << "''TIME BANK'' APPLICATION\n\n"
         << "Instructor: Mr.Tran Duc Linh\n"
         << "Group: Group No.11\n"
         << "s3974735, Tran Manh Cuong\n"
         << "s3965528, Truong Quang Bao Loc\n"
         << "s3978598, Phan Nhat Minh\n"
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
            default:
                choice = InputValidator::getInt("Invalid option. Please enter again (1-3): ");
                break;
        }
    } while (!exit);
}

void Menu::loginAsGuest() {
    bool exitLoop = false;
    while (!exitLoop) {
        cout << "\n---------- Guest Menu ----------\n";
        int choice = MenuOptionsGenerator::showMenuWithSelect(
            "Choose an action: ",
            {"Exit",
            "Sign up",
            "View supporter details"});
        switch (choice) {
            case 0:
                FileManager::saveMemberDatabase(Menu::allMembers);
                cout << "Database saved successfully!\n";
                cout << "Exit the program...\n";
                cout << "Thank you for using our app! Have a nice day!\n\n";
                exitLoop = true;
                break;
            case 1:
                GuestController::signUp();
                break;
            case 2:
                TableGenerator::generateMemberTable("All Supporters", Menu::allMembers);
                break;
            default:
                cout << "Invalid option. Please enter again!\n";
                break;
        }
    }
}

void Menu::loginAsMember() {
    Member *currentMember = MemberController::login();
    if (currentMember == nullptr) {
        return;
    }
    bool exitLoop = false;
    while (!exitLoop) {
        cout << "\n---------- Member Menu ----------\n";
        int choice = MenuOptionsGenerator::showMenuWithSelect(
            "Choose an action: ",
            {"Exit",
            "View your information",
            "Top up your credit point",
            "Manage your availability",
            "Manage your requests",
            "Search for supporters",
            "Create new request",
            "Rate and review host/supporter",
            "Block/unblock member"});
        switch (choice) {
            case 0:
                FileManager::saveMemberDatabase(Menu::allMembers);
                cout << "Database saved successfully!\n";
                cout << "Exit the program...\n";
                cout << "Thank you for using our app! Have a nice day!\n\n";
                exitLoop = true;
                break;
            case 1:
                currentMember->showInfo();
                break;
            case 2:
                MemberController::topUpCredits(currentMember);
                break;
            case 3:
                MemberController::manageAvailability(currentMember);
                break;
            case 4:
                MemberController::manageRequests(currentMember);
                break;
            case 5:
                MemberController::searchForSupporters(currentMember);
                break;
            case 6:
                MemberController::createRequest(currentMember);
                break;
            case 7:
                MemberController::rateMember(currentMember);
                break;
            case 8:
                MemberController::adjustBlockedMembersList(currentMember);
                break;
            default:
                cout << "Invalid option. Please enter again!\n";
                break;
        }
    }
}

void Menu::loginAsAdmin() {
    Admin admin = AdminController::login();
    if (admin.getUsername() == "") {
        return;
    }
    bool exitLoop = false;
    while (!exitLoop) {
        cout << "\n---------- Admin Menu ----------\n";
        int choice = MenuOptionsGenerator::showMenuWithSelect("Choose an action:", {"Exit", "Reset password for member"});
        switch (choice) {
            case 0:
                FileManager::saveMemberDatabase(Menu::allMembers);
                cout << "Database saved successfully!\n";
                cout << "Exit the program...\n";
                cout << "Thank you for using our app! Have a nice day!\n\n";
                exitLoop = true;
                break;
            case 1:
                admin.resetPassword();
                break;
            default:
                cout << "Invalid option. Please enter again!\n";
                break;
        }
    }
}
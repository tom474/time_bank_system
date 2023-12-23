#include <iostream>
#include "Menu.h"
#include "../utils/InputValidator.h"
#define GUEST = 1
#define MEMBER = 1
#define ADMIN = 1

Menu::Menu() { this->currentScreen = "Welcome"; }

void Menu::showWelcome()
{
    cout << "EEET2482/COSC2082 ASSIGNMENT \n"
         << "''TIME BANK'' APPLICATION \n\n"
         << "Instructor : Mr.Tran Duc Linh \n"
         << "Group: Group No.11 \n"
         << "s3804811, Pham Quang Man \n"
         << "s3804811, Pham Quang Man \n"
         << "s3804811, Pham Quang Man \n"
         << "s3804811, Pham Quang Man \n"
         << "Use the app as 1. Guest    2. Member   3. Admin\n\n";

    // Get choice input from user
    int choice = InputValidator::getInt("Please select a login option (1/2/3): ");
    bool exit = false;
    do
    {
        switch (choice)
        {
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
            choice = InputValidator::getInt("Invalid option. Please enter the correct login option (1/2/3): ");
            break;
        }

    } while (!exit); // Exit while loop after correct choice is selected
}

void Menu::loginAsGuest()
{
    cout << "Logging in as Guest";
}

void Menu::loginAsMember()
{

    cout << "Logging in as Member";
}

void Menu::loginAsAdmin()
{

    cout << "Logging in as Admin";
}
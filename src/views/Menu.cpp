#include <iostream>
#include "Menu.h"

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
         << "Use the app as 1. Guest    2. Member   3. Admin\n\n"
         << "Enter your choice: ";
}
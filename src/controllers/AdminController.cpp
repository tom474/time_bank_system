#include "./AdminController.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

Admin AdminController::login() {
    cout << "\n---------- Login ----------\n";
    string username = InputValidator::getString("Please enter your username: ");
    string password = InputValidator::getString("Please enter your password: ");
    bool found = false;
    Admin admin = FileManager::loadAdminDatabase();
    if (password == admin.getPassword() && username == admin.getUsername()) {
        cout << "Login Successfully!\n";
        return admin;
    }
    cout << "Error: User does not exist!\n";
    return Admin();
}

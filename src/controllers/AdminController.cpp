#include "./AdminController.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

Admin AdminController::login() {
    // string password = "123456";
    // string username = "loctruong";

    cout << "---------- Login ----------\n";
    string username = InputValidator::getString("Please enter your username: ");
    string password = InputValidator::getString("Please enter your password: ");
    bool found = false;
    Admin admin = FileManager::loadAdminDatabase();
    if (password == admin.getPassword() && username == admin.getUsername()) {
        cout << "Login Successfully!\n" << endl;
        return admin;
        // Member *newMember = new (std::nothrow) Member(username, password, memberID, fullname, creditPoint, phoneNumber, email, homeAddress, city, availableStatus, skills, availability, blockedUsers, requests, reviews);
        // allMembers.push_back(newMember);
    }
    cout << "Error: User does not exist!" << endl;
    return Admin();
    // if (loggedInMember.getMemberId() != )
    // {
    //     cout << "FOUND";
    //     loggedInMember.showInfo();
    // }
}

#include "./Admin.h"

#include <iostream>

Admin::Admin() {}

Admin::Admin(string usernameVal = "", string passwordVal = "")
: User(usernameVal, passwordVal) {}

string Admin::getUsername() {
    return User::getUsername();
}

void Admin::setUsername(string usernameVal) {
    User::setUsername(usernameVal);
}

string Admin::getPassword() {
    return User::getPassword();
}

void Admin::setPassword(string passwordVal) {
    User::setPassword(passwordVal);
}

void Admin::resetPassword() {
    // Show all members
    TableGenerator::generateMemberTable("All members", Menu::allMembers);

    if (Menu::allMembers.size() == 0) {
        return;
    }

    cout << "\n---------- Reset Password ----------\n";
    bool isGetMemberId = false;
    Member* targetMember = nullptr;
    // Get the target user
    while(!isGetMemberId) {
        string memberUsername = InputValidator::getString("Enter member's ID that you want to reset password: ");
        vector<Member*> members = Menu::allMembers;
        // Find the target user
        for (Member* member : members) {
            if (member->getMemberId() == memberUsername) {
                targetMember = member;
                isGetMemberId = true;
            }
        }
        if (targetMember == nullptr) {
            cout << "Error: Member does not exist!\n";
        }
    }
    // Reset password and set IsResetPassword to true
    string newPassword = InputValidator::getString("Enter new password: ");
    targetMember->setPassword(newPassword);
    targetMember->setIsResetPassword(true);
    cout << "Reset password successfully!\n";
}

Admin::~Admin() {}
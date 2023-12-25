#include "./MemberController.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

Member* MemberController::login() {
    // string password = "123456";
    // string username = "loctruong";

    cout << "---------- Login ----------\n";
    string username = InputValidator::getString("Please enter your username: ");
    string password = InputValidator::getString("Please enter your password: ");
    Member* loggedInMember;
    vector<Member* > members = Menu::allMembers;
    for (Member *member : members) {
        if (password == member->getPassword() && username == member->getUsername()) {
            cout << "LOGGED IN SUCCESS" << endl;
            loggedInMember = member;
            return loggedInMember;
        }
    }
    cout << "ERROR: COULD NOT FIND" << endl;
    return nullptr;
}

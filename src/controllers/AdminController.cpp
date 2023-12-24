#include "./AdminController.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

bool AdminController::login()
{
    // string password = "123456";
    // string username = "loctruong";

    cout << "---------- Login ----------\n";
    string username = InputValidator::getString("Please enter your username: ");
    string password = InputValidator::getString("Please enter your password: ");
    Member loggedInMember;
    bool found = false;
    vector<Member *> allMembers = FileManager::loadMemberDatabase();
    for (Member *member : allMembers)
    {
        if (password == member->getPassword() && username == member->getUsername())
        {
            cout << "LOGGED IN SUCCESS" << endl;
            loggedInMember = *member;
            found = true;
            break;
            // Member *newMember = new (std::nothrow) Member(username, password, memberID, fullname, creditPoint, phoneNumber, email, homeAddress, city, availableStatus, skills, availability, blockedUsers, requests, reviews);
            // allMembers.push_back(newMember);
        }
    }
    if (!found)
    {
        cout << "ERROR: COULD NOT FIND" << endl;
        return false;
    }
    return true;
    // if (loggedInMember.getMemberId() != )
    // {
    //     cout << "FOUND";
    //     loggedInMember.showInfo();
    // }
}

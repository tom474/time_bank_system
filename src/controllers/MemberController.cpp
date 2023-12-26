#include "./MemberController.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;

Member* MemberController::login() {
    cout << "---------- Login ----------\n";
    string username = InputValidator::getString("Please enter your username: ");
    string password = InputValidator::getString("Please enter your password: ");
    Member* loggedInMember;
    vector<Member* > members = Menu::allMembers;
    for (Member *member : members) {
        if (password == member->getPassword() && username == member->getUsername()) {
            cout << "Login Successfully!\n" << endl;
            loggedInMember = member;
            MemberController::resetPassword(loggedInMember);
            return loggedInMember;
        }
    }
    cout << "Error: User does not exist!" << endl;
    return nullptr;
}

void MemberController::viewMemberList(vector<Member*> members) {
    // Calculate the maximum length for each column
    size_t idWidth = 8;
    size_t usernameWidth = 0;
    size_t skillWidth = 0;
    size_t phoneNumberWidth = 12;
    size_t emailWidth = 0;
    size_t homeAddressWidth = 0;
    size_t cityWidth = 8;
    size_t statusWidth = 6;

    for (Member* member : members) {
        usernameWidth = std::max(usernameWidth, member->getUsername().length());
        skillWidth = std::max(skillWidth, Converter::skillsToString(member->getSkill()).length());
        emailWidth = std::max(emailWidth, member->getEmail().length());
        homeAddressWidth = std::max(homeAddressWidth, member->getHomeAddress().length());
    }

    // Print a line separator
    std::cout << std::string(idWidth + usernameWidth + skillWidth + phoneNumberWidth + emailWidth + homeAddressWidth + cityWidth + statusWidth + 25, '-') << "\n";

    // Print the header
    std::cout << "| " << std::left << std::setw(idWidth) << "ID" << " | "
              << std::setw(usernameWidth) << "Username" << " | "
              << std::setw(skillWidth) << "Skills" << " | "
              << std::setw(phoneNumberWidth) << "Phone Number" << " | "
              << std::setw(emailWidth) << "Email" << " | "
              << std::setw(homeAddressWidth) << "Home Address" << " | "
              << std::setw(cityWidth) << "City" << " | "
              << std::setw(statusWidth) << "Status" << " |\n";

    // Print a line separator
    std::cout << std::string(idWidth + usernameWidth + skillWidth + phoneNumberWidth + emailWidth + homeAddressWidth + cityWidth + statusWidth + 25, '-') << "\n";

    // Print the member information
    for (Member* member : members) {
        std::cout << "| " << std::left << std::setw(idWidth) << member->getMemberId() << " | "
                  << std::setw(usernameWidth) << member->getUsername() << " | "
                  << std::setw(skillWidth) << Converter::skillsToString(member->getSkill()) << " | "
                  << std::setw(phoneNumberWidth) << member->getPhoneNumber() << " | "
                  << std::setw(emailWidth) << member->getEmail() << " | "
                  << std::setw(homeAddressWidth) << member->getHomeAddress() << " | "
                  << std::setw(cityWidth) << member->getAvailableCity() << " | "
                  << std::setw(statusWidth) << Converter::boolToString(member->getAvailableStatus()) << " |"
                  << "\n";
    }
    // Print a line separator
    std::cout << std::string(idWidth + usernameWidth + skillWidth + phoneNumberWidth + emailWidth + homeAddressWidth + cityWidth + statusWidth + 25, '-') << "\n\n";
}

void MemberController::resetPassword(Member* member) { 
    if (!member->getIsResetPassword()) {
        return;
    }
    cout << "Your password has been reset!\n"; 
    string newPassword = InputValidator::getString("Enter new password: ");
    member->setPassword(newPassword);
    member->setIsResetPassword(false);
}

void MemberController::adjustBlockedMembersList(Member* currentMember) {
    vector<string> blockedMembersStr = currentMember->getBlockedUsers();

    vector<Member*> blockedMembers = {};
    vector<Member*> notBlockedMembers = {};
    for (Member* member : Menu::allMembers) {
        if (std::find(blockedMembersStr.begin(), blockedMembersStr.end(), member->getMemberId()) != blockedMembersStr.end()) {
            blockedMembers.push_back(member);
        } else if (member->getMemberId() != currentMember->getMemberId()){
            notBlockedMembers.push_back(member);
        }
    }

    cout << "---------- Block/Unblock Member ----------\n";
    int choice = MenuOptionsGenerator::showMenuWithSelect("Choose an action: ", {"Block member", "Unblock member"});
    switch (choice) {
        case 1: {
            viewMemberList(notBlockedMembers);
            bool isValidID = false;
            while (!isValidID) {
                string blockedMemberID = InputValidator::getString("Enter the member's ID that you want to block: ");
                for (Member* member : notBlockedMembers) {
                    if (member->getMemberId() == blockedMemberID) {
                        currentMember->blockMember(*member);
                        isValidID = true;
                        break;
                    }
                }
                if (!isValidID) {
                    cout << "Invalid ID. Please enter again!\n";
                }
            }
            break;
        } case 2: {
            viewMemberList(blockedMembers);
            bool isValidID = false;
            while (!isValidID) {
                string unblockedMemberID = InputValidator::getString("Enter the member's ID that you want to unblock: ");
                for (Member* member : blockedMembers) {
                    if (member->getMemberId() == unblockedMemberID) {
                        currentMember->unblockMember(*member);
                        isValidID = true;
                        break;
                    }
                }
                if (!isValidID) {
                    cout << "Invalid ID. Please enter again!\n";
                }
            }
            break;
        } default:
            break;
    }
}
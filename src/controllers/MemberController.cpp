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
    size_t fullnameWidth = 0;
    size_t skillWidth = 0;
    size_t phoneNumberWidth = 12;
    size_t emailWidth = 0;
    size_t homeAddressWidth = 0;
    size_t cityWidth = 8;
    size_t statusWidth = 6;

    for (Member* member : members) {
        fullnameWidth = std::max(fullnameWidth, member->getFullname().length());
        skillWidth = std::max(skillWidth, Converter::skillsToString(member->getSkill()).length());
        emailWidth = std::max(emailWidth, member->getEmail().length());
        homeAddressWidth = std::max(homeAddressWidth, member->getHomeAddress().length());
    }

    // Print a line separator
    std::cout << std::string(idWidth + fullnameWidth + skillWidth + phoneNumberWidth + emailWidth + homeAddressWidth + cityWidth + statusWidth + 25, '-') << "\n";

    // Print the header
    std::cout << "| " << std::left << std::setw(idWidth) << "ID" << " | "
              << std::setw(fullnameWidth) << "Fullname" << " | "
              << std::setw(skillWidth) << "Skills" << " | "
              << std::setw(phoneNumberWidth) << "Phone Number" << " | "
              << std::setw(emailWidth) << "Email" << " | "
              << std::setw(homeAddressWidth) << "Home Address" << " | "
              << std::setw(cityWidth) << "City" << " | "
              << std::setw(statusWidth) << "Status" << " |\n";

    // Print a line separator
    std::cout << std::string(idWidth + fullnameWidth + skillWidth + phoneNumberWidth + emailWidth + homeAddressWidth + cityWidth + statusWidth + 25, '-') << "\n";

    // Print the member information
    for (Member* member : members) {
        std::cout << "| " << std::left << std::setw(idWidth) << member->getMemberId() << " | "
                  << std::setw(fullnameWidth) << member->getFullname() << " | "
                  << std::setw(skillWidth) << Converter::skillsToString(member->getSkill()) << " | "
                  << std::setw(phoneNumberWidth) << member->getPhoneNumber() << " | "
                  << std::setw(emailWidth) << member->getEmail() << " | "
                  << std::setw(homeAddressWidth) << member->getHomeAddress() << " | "
                  << std::setw(cityWidth) << member->getAvailableCity() << " | "
                  << std::setw(statusWidth) << Converter::boolToString(member->getAvailableStatus()) << " |"
                  << "\n";
    }
    // Print a line separator
    std::cout << std::string(idWidth + fullnameWidth + skillWidth + phoneNumberWidth + emailWidth + homeAddressWidth + cityWidth + statusWidth + 25, '-') << "\n\n";
}

void MemberController::resetPassword(Member* member) { 
    // Check if member has a temporary password 
    if (!member->getIsResetPassword()) {
        return;
    }
    // Show request to reset password and set IsResetPassword to false
    cout << "Your password has been reset!\n"; 
    string newPassword = InputValidator::getString("Enter new password: ");
    member->setPassword(newPassword);
    member->setIsResetPassword(false);
}

vector<Member*> MemberController::searchForSupporters(Member* currentMember) {
    // Show current member's information
    cout << "--------- Your Information --------\n";
    cout << "| " << std::left << std::setw(16) << "Credit Point" << " | " << std::setw(12) << currentMember->getCreditPoint() << " |\n";
    cout << "| " << std::left << std::setw(16) << "Host Rating" << " | " << std::setw(12) << currentMember->getHostRating() << " |\n";
    cout << "| " << std::left << std::setw(16) << "City" << " | " << std::setw(12) << currentMember->getAvailableCity() << " |\n";
    cout << "-----------------------------------\n\n";

    // Show the list of suitable supporters
    vector<Member*> supporters = {};
    for (Member* supporter : Menu::allMembers) {
        bool isSuitable = false;

        // Check if the supporter is the current member
        if (supporter->getMemberId() == currentMember->getMemberId()) {
            continue;
        }

        // Check if the supporter is blocked by the current member
        if (std::find(currentMember->getBlockedUsers().begin(), currentMember->getBlockedUsers().end(), supporter->getMemberId()) != currentMember->getBlockedUsers().end()) {
            continue;
        }

        // Check if the current member is blocked by the supporter
        if (std::find(supporter->getBlockedUsers().begin(), supporter->getBlockedUsers().end(), currentMember->getMemberId()) != supporter->getBlockedUsers().end()) {
            continue;
        }

        // Check available status of the supporter
        if (supporter->getAvailableStatus() == false) {
            continue;
        }

        // Check if supporter is living at the same city with the member
        if (supporter->getAvailableCity() != currentMember->getAvailableCity()) {
            continue;
        }

        // Check if the current member has the host rating greater than the supporter's min host rating
        // And check if current member has enough credit point to book the supporter
        for (Availability* availability : supporter->getAvailability()) {
            if (availability->getMinHostRating() <= currentMember->getHostRating() && availability->getPointPerHour() <= currentMember->getCreditPoint()) {
                isSuitable = true;
                break;
            }
        }
        
        // If the supporter is suitable, add to the list
        if (isSuitable) {
            supporters.push_back(supporter);
        }
    }

    if (supporters.size() == 0) {
        cout << "There is no suitable supporter for you!\n";
    } else {
        // Show the list of suitable supporters
        cout << "------------------------------------------------------ List of suitable supporters ------------------------------------------------------\n";
        MemberController::viewMemberList(supporters);
    }

    return supporters;
}

void MemberController::createRequest(Member* currentMember) {
    vector<Member*> supporters = MemberController::searchForSupporters(currentMember);
    if (supporters.size() == 0) {
        return;
    }

    // Choose a supporter to create a request
    bool isValidID = false;
    Member* supporter;
    while (!isValidID) {
        string supporterID = InputValidator::getString("Enter the supporter's ID that you want to create a request: ");
        for (Member* member : supporters) {
            if (member->getMemberId() == supporterID) {
                supporter = member;
                isValidID = true;
                break;
            }
        }
        if (!isValidID) {
            cout << "Invalid ID. Please enter again!\n";
        }
    }
    cout << "\n";

    // Get suitable availability of the supporter
    vector<Availability*> suitableAvailability = {};
    for (Availability* availability : supporter->getAvailability()) {
        if (availability->getMinHostRating() <= currentMember->getHostRating() && availability->getPointPerHour() <= currentMember->getCreditPoint()) {
            suitableAvailability.push_back(availability);
        }
    }

    // Check if there is no suitable availability
    if (suitableAvailability.size() == 0) {
        cout << "There is no suitable availability for you!\n";
        return;
    }

    // Show suitable availability
    size_t skillWidth = 0;

    for (Availability* availability : suitableAvailability) {
        skillWidth = std::max(skillWidth, Converter::skillsToString(availability->getPerformedSkills()).length());
    }

    cout << std::string((skillWidth + 70)/2 - 11, '-') << " Suitable Availability " << std::string((skillWidth + 70)/2 - 11, '-') << "\n";
    // Print a line separator
    std::cout << std::string(8 + 16 + 16 + skillWidth + 14 + 16, '-') << "\n";

    std::cout << "| " << std::left << std::setw(8) << "Session" << " | "
            << std::setw(16) << "Start Time" << " | "
            << std::setw(16) << "End Time" << " | "
            << std::setw(skillWidth) << "Skills" << " | "
            << std::setw(14) << "Point Per Hour" << " |\n";

    // Print a line separator
    std::cout << std::string(8 + 16 + 16 + skillWidth + 14 + 16, '-') << "\n";

    // Print the availability information
    int session = 1;
    for (Availability* availability : supporter->getAvailability()) {
        std::cout << "| " << std::left << std::setw(8) << session << " | "
                << std::setw(16) << availability->getAvailableTime()->getStartTime().toString() << " | "
                << std::setw(16) << availability->getAvailableTime()->getEndTime().toString() << " | "
                << std::setw(skillWidth) << Converter::skillsToString(availability->getPerformedSkills()) << " | "
                << std::right << std::setw(14) << availability->getPointPerHour() << " |\n";
        session++;
    }

    // Print a line separator
    std::cout << std::string(8 + 16 + 16 + skillWidth + 14 + 16, '-') << "\n\n";

    // Create a request
    cout << "---------- Create a request ----------\n";
    string requestID = IdGenerator::generateRequestId();

    // Choose a session
    Availability* selectedAvailability;
    bool isValidSession = false;
    while (!isValidSession) {
        int session = InputValidator::getInt("Enter the session that you want to create a request: ");
        if (session < 1 || session > supporter->getAvailability().size()) {
            cout << "Invalid session. Please enter again!\n";
            continue;
        }
        selectedAvailability = supporter->getAvailability()[session - 1];
        isValidSession = true;
    }

    // Check the maximum hours that the current member can request
    int maxHours = currentMember->getCreditPoint() / selectedAvailability->getPointPerHour();
    cout << "You can request for " << maxHours << " hours at most!\n";

    // Get desired time
    bool isValidTime = false;
    TimePeriod* timePeriod;
    while (!isValidTime) {
        // Get desired time
        string startDate, startTime;
        string endDate, endTime;
        int startHour, endHour;
        int startMinute, endMinute;

        startDate = InputValidator::getDate("Enter your desired start date (dd/mm/yyyy): ");
        startTime = InputValidator::getTime("Enter your desired start time (hh:mm): ");
        endDate = InputValidator::getDate("Enter your desired end date (dd/mm/yyyy): ");
        endTime = InputValidator::getTime("Enter your desired end time (hh:mm): ");

        startHour = Converter::stringToInteger(startTime.substr(0, 2));
        startMinute = Converter::stringToInteger(startTime.substr(3, 2));
        endHour = Converter::stringToInteger(endTime.substr(0, 2));
        endMinute = Converter::stringToInteger(endTime.substr(3, 2));

        Time time1(startDate, startHour, startMinute);
        Time time2(endDate, endHour, endMinute);
        timePeriod = new (std::nothrow) TimePeriod(time1, time2);

        // Check if the desired time is valid (overlaps with selected availability and the requested hours is less than or equal the maximum hours)
        if (selectedAvailability->getAvailableTime()->isOverlapsWith(*timePeriod)) {
            if (timePeriod->getHourDuration() <= maxHours) {
                isValidTime = true;
            } else {
                cout << "You can only request for " << maxHours << " hours!\n";
            }
        } else {
            cout << "Invalid time. Please enter again!\n";
        }
    }
    cout << "\n";

    // Get desired skills
    vector<Skill*> desiredSkills = {};
    bool isAddSkill = true;
    while (isAddSkill) {
        bool isValidSkill = false;
        while (!isValidSkill) {
            // Show the list of supporter's available skills
            cout << "Available skills that you can request: \n";
            for (int i = 0; i < selectedAvailability->getPerformedSkills().size(); i++) {
                cout << i + 1 << ". " << selectedAvailability->getPerformedSkills()[i]->getName() << "\n";
            }

            // Choose a skill
            int choice = InputValidator::getInt("Enter a choice: ");
            if (choice < 1 || choice > selectedAvailability->getPerformedSkills().size()) {
                cout << "Invalid choice. Please enter again!\n";
                continue;
            }

            // Check if the skill is already chosen
            if (std::find(desiredSkills.begin(), desiredSkills.end(), selectedAvailability->getPerformedSkills()[choice - 1]) != desiredSkills.end()) {
                cout << "You have already chosen this skill!\n";
                break;
            }

            desiredSkills.push_back(selectedAvailability->getPerformedSkills()[choice - 1]);
            isValidSkill = true;
        }

        // Ask if the member wants to add another skill
        if (selectedAvailability->getPerformedSkills().size() > 1) {
            isAddSkill = InputValidator::getBool("Do you want to add another skill? (yes/no): ");
        } else {
            isAddSkill = false;
        }
    }

    // Create a request
    Request* request = new Request(requestID, currentMember->getMemberId(), supporter->getMemberId(), timePeriod, desiredSkills, requestStatus::Pending);
    currentMember->sendRequest(*request);
    supporter->receiveRequest(*request);

    cout << "\nRequest created successfully!\n\n";
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
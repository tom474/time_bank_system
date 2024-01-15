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
    cout << "\n---------- Login ----------\n";
    string username = InputValidator::getString("Please enter your username: ");
    string password = InputValidator::getString("Please enter your password: ");
    Member *loggedInMember;
    vector<Member *> members = Menu::allMembers;
    for (Member *member : members) {
        if (password == member->getPassword() && username == member->getUsername()) {
            cout << "Login Successfully!\n";
            loggedInMember = member;
            MemberController::resetPassword(loggedInMember);
            return loggedInMember;
        }
    }
    cout << "Error: User does not exist!" << endl;
    return nullptr;
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
    cout << "Change password successfully!\n";
}

vector<Member *> MemberController::searchForSupporters(Member *currentMember) {
    // Show current member's information
    size_t width = 12;
    if (Converter::blockedUsersToString(currentMember->getBlockedUsers()).length() > width) {
        width = Converter::blockedUsersToString(currentMember->getBlockedUsers()).length();
    }

    // Print the title
    string title = "Your Information";
    size_t titleLength = title.length() + 2;
    size_t tableWidth = width + 23;
    size_t leftPadding = (tableWidth - titleLength) / 2;
    size_t rightPadding = tableWidth - titleLength - leftPadding;

    cout << "\n";
    std::cout << std::string(leftPadding, '-') << " " << title << " " << std::string(rightPadding, '-') << "\n";

    // Print the line separator
    std::cout << std::string(tableWidth, '-') << "\n";

    // Print the information
    cout << "| " << std::left << std::setw(16) << "Credit Point" << " | " << std::setw(width) << currentMember->getCreditPoint() << " |\n";
    cout << "| " << std::left << std::setw(16) << "Host Rating" << " | " << std::setw(width) << std::fixed << std::setprecision(1) << currentMember->getHostRating() << " |\n";
    cout << "| " << std::left << std::setw(16) << "City" << " | " << std::setw(width) << currentMember->getAvailableCity() << " |\n";
    cout << "| " << std::left << std::setw(16) << "Blocked Users" << " | " << std::setw(width) << Converter::blockedUsersToString(currentMember->getBlockedUsers()) << " |\n";

    // Print the line separator
    std::cout << std::string(tableWidth, '-') << "\n";

    cout << "\n---------- Search for Supporters ----------\n";
    // Prompt the current member to enter their desired time
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
    TimePeriod *timePeriod = new (std::nothrow) TimePeriod(time1, time2);

    // Show the list of suitable supporters
    vector<Member *> supporters = {};
    for (Member *supporter : Menu::allMembers) {
        bool isSuitable = false;

        // Check if the supporter is the current member
        if (supporter->getMemberId() == currentMember->getMemberId()) {
            continue;
        }

        // Check if the supporter is blocked by the current member
        if (currentMember->getBlockedUsers().size() > 0) {
            bool isBlocked = false;
            for (string blockedUser : currentMember->getBlockedUsers()) {
                if (blockedUser == supporter->getMemberId()) {
                    isBlocked = true;
                    break;
                }
            }
            if (isBlocked) {
                continue;
            }
        }

        // Check if the current member is blocked by the supporter
        if (supporter->getBlockedUsers().size() > 0) {
            bool isBlocked = false;
            for (string blockedUser : supporter->getBlockedUsers()) {
                if (blockedUser == currentMember->getMemberId()) {
                    isBlocked = true;
                    break;
                }
            }
            if (isBlocked) {
                continue;
            }
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
        // And check if the supporter's availability is suitable for the current member's desired time
        for (Availability *availability : supporter->getAvailability()) {
            if (availability->getMinHostRating() <= currentMember->getHostRating() && availability->getPointPerHour() <= currentMember->getCreditPoint() && availability->getAvailableTime()->isOverlapsWith(*timePeriod)) {
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
        TableGenerator::generateSupporterTable("Suitable Supporters", supporters);
    }

    return supporters;
}

void MemberController::createRequest(Member *currentMember) {
    vector<Member *> supporters = MemberController::searchForSupporters(currentMember);
    if (supporters.size() == 0) {
        return;
    }

    cout << "\n---------- Create a Request ----------\n";
    // Choose a supporter to create a request
    bool isValidID = false;
    Member *supporter;
    while (!isValidID) {
        string supporterID = InputValidator::getString("Enter the supporter's ID that you want to create a request: ");
        for (Member *member : supporters) {
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

    // Get suitable availability of the supporter
    vector<Availability *> suitableAvailability = {};
    for (Availability *availability : supporter->getAvailability()) {
        if (availability->getMinHostRating() <= currentMember->getHostRating() && availability->getPointPerHour() <= currentMember->getCreditPoint()) {
            suitableAvailability.push_back(availability);
        }
    }

    // Check if there is no suitable availability
    if (suitableAvailability.size() == 0) {
        cout << "There is no suitable availability for you!\n";
        return;
    }

    // Show the list of suitable availability
    TableGenerator::generateAvailabilityTable("Suitable Availability", suitableAvailability);

    // Create a request
    cout << "\n---------- Create a request ----------\n";
    string requestID = IdGenerator::generateRequestId();

    // Choose a session
    Availability *selectedAvailability;
    bool isValidSession = false;
    while (!isValidSession) {
        int session = InputValidator::getInt("Enter the session that you want to create a request: ");
        if (session < 1 || session > suitableAvailability.size()) {
            cout << "Invalid session. Please enter again!\n";
            continue;
        }
        selectedAvailability = suitableAvailability[session - 1];
        isValidSession = true;
    }

    // Check the maximum hours that the current member can request
    int maxHours;
    if (selectedAvailability->getAvailableTime()->getHourDuration() < (currentMember->getCreditPoint() / selectedAvailability->getPointPerHour())) {
        maxHours = selectedAvailability->getAvailableTime()->getHourDuration();
    } else {
        maxHours = currentMember->getCreditPoint() / selectedAvailability->getPointPerHour();
    }
    cout << "You can request for " << maxHours << " hours at most!\n";

    // Get desired time
    bool isValidTime = false;
    TimePeriod *timePeriod;
    while (!isValidTime) {
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
    vector<Skill *> desiredSkills = {};
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
        }
        else {
            isAddSkill = false;
        }
    }

    // Create a request
    Request *request = new Request(requestID, currentMember->getMemberId(), supporter->getMemberId(), timePeriod, desiredSkills, requestStatus::Pending);
    currentMember->sendRequest(*request);
    supporter->receiveRequest(*request);

    cout << "Request created successfully!\n";
}

void MemberController::adjustBlockedMembersList(Member *currentMember) {
    vector<string> blockedMembersStr = currentMember->getBlockedUsers();
    vector<Member *> blockedMembers = {};
    vector<Member *> notBlockedMembers = {};
    for (Member *member : Menu::allMembers) {
        if (std::find(blockedMembersStr.begin(), blockedMembersStr.end(), member->getMemberId()) != blockedMembersStr.end()) {
            blockedMembers.push_back(member);
        } else if (member->getMemberId() != currentMember->getMemberId()) {
            notBlockedMembers.push_back(member);
        }
    }

    cout << "\n---------- Block/Unblock Member ----------\n";
    int choice = MenuOptionsGenerator::showMenuWithSelect("Choose an action: ", {"Block member", "Unblock member"});
    switch (choice) {
    case 1: {
        if (notBlockedMembers.size() == 0) {
            cout << "There is no member left to block!\n";
            break;
        }
        TableGenerator::generateMemberTable("Not Blocked Members", notBlockedMembers);
        cout << "\n---------- Block Member ----------\n";
        bool isValidID = false;
        while (!isValidID) {
            string blockedMemberID = InputValidator::getString("Enter the member's ID that you want to block: ");
            for (Member *member : notBlockedMembers) {
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
    }
    case 2: {
        if (blockedMembers.size() == 0) {
            cout << "You didn't blocked any members!\n";
            break;
        }
        TableGenerator::generateMemberTable("Blocked Members", blockedMembers);
        cout << "\n---------- Unblock Member ----------\n";
        bool isValidID = false;
        while (!isValidID) {
            string unblockedMemberID = InputValidator::getString("Enter the member's ID that you want to unblock: ");
            for (Member *member : blockedMembers) {
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

    }
    default:
        cout << "Invalid option. Please enter again!\n";
        break;
    }
}

void MemberController::manageAvailability(Member* currentMember) {
    bool exitChoice = false;
    while (!exitChoice) {
        cout << "\n---------- Manage Availability ----------\n";
        int choice = MenuOptionsGenerator::showMenuWithSelect(
            "Choose an action: ", {
                "Exit",
                "Set your available status",
                "Add availability",
                "Remove availability"
            }
        );
        switch (choice) {
            case 0:
                exitChoice = true;
                break;
            case 1: {
                cout << "\n---------- Set Availability ----------\n";
                cout << "Current available status: " << (currentMember->getAvailableStatus() ? "Available" : "Unavailable") << "\n";
                bool isAvailable = InputValidator::getBool("Do you want to change your status? (yes/no): ");
                if (isAvailable) {
                    currentMember->setAvailableStatus(!currentMember->getAvailableStatus());
                    cout << "Your available status has been updated! Your available status: " << (currentMember->getAvailableStatus() ? "Available" : "Unavailable") << "\n";
                }
                break;
            }
            case 2: {
                if (currentMember->getAvailability().size() > 0) {
                    TableGenerator::generateAvailabilityTable("Your Current Availability", currentMember->getAvailability());
                }
                currentMember->addAvailability();
                break;
            }
            case 3: {
                if (currentMember->getAvailability().size() > 0) {
                    TableGenerator::generateAvailabilityTable("Your Current Availability", currentMember->getAvailability());
                    currentMember->removeAvailability();
                    break;
                } else {
                    cout << "There is no availability to remove!\n";
                    break;
                }
            }
            default:
                exitChoice = true;
                break;
        }
    }
}

void MemberController::manageRequests(Member* currentMember) {
    bool exitLoop = false;
    while (!exitLoop) {
        cout << "\n---------- Manage Request ----------\n";
        int choice = MenuOptionsGenerator::showMenuWithSelect(
            "Choose an action: ",
            {"Exit",
            "View your sending requests",
            "View your receiving requests",
            "Accept a receiving requests",
            "Reject a receiving requests"});
        switch (choice) {
            case 0:
                exitLoop = true;
                break;
            case 1:
                // Check if the current member has any sending request
                if (currentMember->getSendingRequest().size() == 0) {
                    cout << "You have no sending request!\n";
                } else {
                    TableGenerator::generateRequestTable("Sending Requests", currentMember->getSendingRequest());
                }
                break;
            case 2:
                // Check if the current member has any receiving request
                if (currentMember->getReceivingRequest().size() == 0) {
                    cout << "You have no receiving request!\n";
                } else {
                    TableGenerator::generateRequestTable("Receiving Requests", currentMember->getReceivingRequest());
                }
                break;
            case 3:
                MemberController::acceptRequest(currentMember);
                break;
            case 4:
                MemberController::rejectRequest(currentMember);
                break;
            default:
                cout << "Invalid option. Please enter again!\n";
                break;
        }
    }
}

void MemberController::acceptRequest(Member* currentMember) {
    // Check if the current member has any receiving request
    if (currentMember->getReceivingRequest().size() == 0) {
        cout << "You have no receiving request!\n";
        return;
    }

    // Show the list of pending requests
    vector<Request*> pendingRequests = {};
    for (Request* request : currentMember->getReceivingRequest()) {
        if (request->getStatus() == "Pending") {
            pendingRequests.push_back(request);
        }
    }
    if (pendingRequests.size() == 0) {
        cout << "You have no pending request!\n";
        return;
    }
    TableGenerator::generateRequestTable("Pending Requests", pendingRequests);

    // Choose a request to accept
    cout << "\n---------- Accept Request ----------\n";
    bool isValidID = false;
    Request* selectedRequest;
    while (!isValidID) {
        string requestID = InputValidator::getString("Enter the request's ID that you want to accept: ");
        for (Request* request : pendingRequests) {
            if (request->getRequestID() == requestID) {
                selectedRequest = request;
                isValidID = true;
                break;
            }
        }

        // Confirm if the current member wants to accept the request
        if (isValidID) {
            bool isConfirm = InputValidator::getBool("Are you confirm to accept this request? (yes/no): ");
            if (isConfirm) {
                selectedRequest->setStatus(requestStatus::Accepted);
                cout << "Request accepted successfully!\n";
            } else {
                cout << "Request acceptance canceled!\n";
            }
        } else {
            cout << "Invalid ID! Please enter again!\n";
        }
    }

    // Get the current member's availability whose time overlaps with the request's time
    Availability *selectedAvailability;
    for (Availability* availability : currentMember->getAvailability()) {
        if (availability->getAvailableTime()->isOverlapsWith(*selectedRequest->getRequestedTime())) {
            selectedAvailability = availability;
            break;
        }
    }

    // Update the current member's availability
    currentMember->updateAvailability(*selectedRequest, *selectedAvailability);

    // Update the credit point of the current member and requesting member
    int pointPerHour = selectedAvailability->getPointPerHour();
    int hourDuration = selectedRequest->getRequestedTime()->getHourDuration();
    int consumingCreditPoint = pointPerHour * hourDuration;
    currentMember->setCreditPoint(currentMember->getCreditPoint() + consumingCreditPoint);

    Member* requestingMember;
    for (Member* member : Menu::allMembers) {
        if (member->getMemberId() == selectedRequest->getHostID()) {
            requestingMember = member;
            break;
        }
    }
    requestingMember->setCreditPoint(requestingMember->getCreditPoint() - consumingCreditPoint);

    // Update the request list of the current member and requesting member (automatically reject non-accepted requests with overlapped time)
    // Check if the requests in the pending request list of the current member overlaps with any availabilities of the current member
    for (Request* request : currentMember->getReceivingRequest()) {
        if (request->getStatus() == "Pending") {
            bool isOverLaps = false;
            for (Availability* availability : currentMember->getAvailability()) {
                if (availability->getAvailableTime()->isOverlapsWith(*request->getRequestedTime())) {
                    isOverLaps = true;
                    break;
                }
            }
            if (!isOverLaps) {
                request->setStatus(requestStatus::Rejected);
            }
        }
    }
}

void MemberController::rejectRequest(Member* currentMember) {
    // Check if the current member has any receiving request
    if (currentMember->getReceivingRequest().size() == 0) {
        cout << "You have no receiving request!\n";
        return;
    }

    // Show the list of pending requests
    vector<Request*> pendingRequests = {};
    for (Request* request : currentMember->getReceivingRequest()) {
        if (request->getStatus() == "Pending") {
            pendingRequests.push_back(request);
        }
    }
    if (pendingRequests.size() == 0) {
        cout << "You have no pending request!\n";
        return;
    }
    TableGenerator::generateRequestTable("Pending Requests", pendingRequests);

    cout << "\n---------- Reject Request ----------\n";
    // Choose a request to reject
    bool isValidID = false;
    Request* selectedRequest;
    while (!isValidID) {
        string requestID = InputValidator::getString("Enter the request's ID that you want to reject: ");
        for (Request* request : pendingRequests) {
            if (request->getRequestID() == requestID) {
                selectedRequest = request;
                isValidID = true;
                break;
            }
        }

        // Confirm if the current member wants to reject the request
        if (isValidID) {
            bool isConfirm = InputValidator::getBool("Are you confirm to reject this request? (yes/no): ");
            if (isConfirm) {
                selectedRequest->setStatus(requestStatus::Rejected);
                cout << "Request rejected successfully!\n";
            } else {
                cout << "Request rejection canceled!\n";
            }
        } else {
            cout << "Invalid ID! Please enter again!\n";
        }
    }
}

void MemberController::topUpCredits(Member* currentMember) {
    if (currentMember == nullptr) {
        std::cerr << "Error: Member is not logged in." << std::endl;
        return;
    }

    cout << "\n---------- Top Up Credit Point ----------\n";
    // Show current credit point
    std::cout << "Your current credit point: " << currentMember->getCreditPoint() << std::endl;

    // Get the amount to top up
    int amount = InputValidator::getInt("Enter the amount that you want to top up: ");

    // Verify password
    string password = InputValidator::getString("Enter your password to confirm: ");
    if (password != currentMember->getPassword()) {
        std::cout << "Incorrect password! Failed to top up your credit point!\n";
        return;
    }

    if (amount > 0) {
        currentMember->creditsTopUp(amount);
        std::cout << "Credit points successfully added! Your current credit point: " 
                  << currentMember->getCreditPoint() << std::endl;
    } else {
        std::cout << "Invalid amount! Failed to top up your credit point!" << std::endl;
    }
}

void MemberController::rateMember(Member* currentMember) {
    bool exitLoop = false;
    while (!exitLoop) {
        cout << "\n---------- Rate & Review Member ----------\n";
        int choice = MenuOptionsGenerator::showMenuWithSelect(
            "Choose an action: ",
            {"Exit",
            "View your request history",
            "Rate and review your host",
            "Rate and review your supporter"});
        switch (choice) {
            case 0:
                exitLoop = true;
                break;
            case 1:
                MemberController::viewRequestHistory(currentMember);
                break;
            case 2:
                MemberController::rateHost(currentMember);
                break;
            case 3:
                MemberController::rateSupporter(currentMember);
                break;
            default:
                cout << "Invalid option. Please enter again!\n";
                break;
        }
    }
}

void MemberController::viewRequestHistory(Member* currentMember) {
    // Check if the current member has any request
    if (currentMember->getSendingRequest().size() == 0 && currentMember->getReceivingRequest().size() == 0) {
        cout << "You have no request!\n";
        return;
    }

    // Show the list of requests
    vector<Request*> requests = {};
    for (Request* request : currentMember->getSendingRequest()) {
        requests.push_back(request);
    }
    for (Request* request : currentMember->getReceivingRequest()) {
        requests.push_back(request);
    }
    TableGenerator::generateRequestTable("Request History", requests);
}

void MemberController::rateHost(Member* currentMember) {
    // Get the accepted receiving request
    vector<Request*> acceptedReceivingRequests = {};
    for (Request* request : currentMember->getReceivingRequest()) {
        if (request->getStatus() == "Accepted") {
            acceptedReceivingRequests.push_back(request);
        }
    }

    // Check if the current member has any accepted sending request
    if (acceptedReceivingRequests.size() == 0) {
        cout << "You have no accepted receiving request!\n";
        return;
    }

    // Show the list of accepted sending requests
    TableGenerator::generateRequestTable("Accepted Receiving Requests", acceptedReceivingRequests);

    // Choose a request to rate
    cout << "\n---------- Rate Host ----------\n";
    bool isValidID = false;
    Request* selectedRequest;
    while (!isValidID) {
        string requestID = InputValidator::getString("Enter the request's ID that you want to rate the host: ");
        for (Request* request : acceptedReceivingRequests) {
            if (request->getRequestID() == requestID) {
                selectedRequest = request;
                isValidID = true;
                break;
            }
        }
        if (!isValidID) {
            cout << "Invalid ID. Please enter again!\n";
        }
    }

    // Get the host
    string hostID = selectedRequest->getHostID();
    Member* host;
    for (Member* member : Menu::allMembers) {
        if (member->getMemberId() == hostID) {
            host = member;
            break;
        }
    }

    // Create review for the host
    string reviewID = IdGenerator::generateReviewId();
    string reviewerID = currentMember->getMemberId();
    string reviewedID = host->getMemberId();
    reviewType type = reviewType::Host;

    bool isValidRatingScore = false;
    int ratingScore;
    while (!isValidRatingScore) {
        ratingScore = InputValidator::getInt("Enter the rating score for the host (1-5): ");
        if (ratingScore < 1 || ratingScore > 5) {
            cout << "Invalid rating score. Please enter again!\n";
        } else {
            isValidRatingScore = true;
        }
    }

    string comment = InputValidator::getString("Enter the comment for the host: ");

    Review* review = new Review(reviewID, reviewerID, reviewedID, type, comment, ratingScore);
    host->addReview(*review);
    cout << "Rate & review host successfully!\n";
}

void MemberController::rateSupporter(Member* currentMember) {
    // Get the accepted sending request
    vector<Request*> acceptedSendingRequests = {};
    for (Request* request : currentMember->getSendingRequest()) {
        if (request->getStatus() == "Accepted") {
            acceptedSendingRequests.push_back(request);
        }
    }

    // Check if the current member has any accepted sending request
    if (acceptedSendingRequests.size() == 0) {
        cout << "You have no accepted sending request!\n";
        return;
    }

    // Show the list of accepted sending requests
    TableGenerator::generateRequestTable("Accepted Sending Requests", acceptedSendingRequests);

    // Choose a request to rate
    cout << "\n---------- Rate Supporter ----------\n";
    bool isValidID = false;
    Request* selectedRequest;
    while (!isValidID) {
        string requestID = InputValidator::getString("Enter the request's ID that you want to rate the supporter: ");
        for (Request* request : acceptedSendingRequests) {
            if (request->getRequestID() == requestID) {
                selectedRequest = request;
                isValidID = true;
                break;
            }
        }
        if (!isValidID) {
            cout << "Invalid ID. Please enter again!\n";
        }
    }

    // Get the supporter
    string supporterID = selectedRequest->getSupporterID();
    Member* supporter;
    for (Member* member : Menu::allMembers) {
        if (member->getMemberId() == supporterID) {
            supporter = member;
            break;
        }
    }

    // Create review for the supporter
    string reviewID = IdGenerator::generateReviewId();
    string reviewerID = currentMember->getMemberId();
    string reviewedID = supporter->getMemberId();
    reviewType type = reviewType::Supporter;

    bool isValidRatingScore = false;
    int ratingScore;
    while (!isValidRatingScore) {
        ratingScore = InputValidator::getInt("Enter the rating score for the supporter (1-5): ");
        if (ratingScore < 1 || ratingScore > 5) {
            cout << "Invalid rating score. Please enter again!\n";
        } else {
            isValidRatingScore = true;
        }
    }

    string comment = InputValidator::getString("Enter the comment for the supporter: ");

    Review* review = new Review(reviewID, reviewerID, reviewedID, type, comment, ratingScore);
    supporter->addReview(*review);

    // Rate supporter's skills
    cout << "\n---------- Rate Supporter's Skills ----------\n";
    for (int i = 0; i < selectedRequest->getRequestedSkills().size(); i++) {
        Skill* skill = selectedRequest->getRequestedSkills()[i];
        bool isValidRatingScore = false;
        cout << "Skill "<< (i + 1) << ": " << skill->getName() << "\n";
        int ratingScore;
        while (!isValidRatingScore) {
            ratingScore = InputValidator::getInt("Enter the rating score for the supporter's '" + skill->getName() + "' skill (1-5): ");
            if (ratingScore < 1 || ratingScore > 5) {
                cout << "Invalid rating score! Please enter again!\n";
            } else {
                isValidRatingScore = true;
            }
        }
        
        // Get the supporter whose skill is rated
        string supporterID = selectedRequest->getSupporterID();
        Member* supporter;
        for (Member* member : Menu::allMembers) {
            if (member->getMemberId() == supporterID) {
                supporter = member;
                break;
            }
        }

        // Find the skill in the supporter's skills
        for (Skill* supporterSkill : supporter->getSkill()) {
            if (supporterSkill->getName() == skill->getName()) {
                supporterSkill->addRatingScore(ratingScore);
                break;
            }
        }        
    }
    cout << "Rate & review supporter successfully!\n";
}
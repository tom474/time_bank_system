#include "Member.h"

#include <iostream>

using std::cout;

Member::Member() {}

Member::Member(
    string usernameVal = "", 
    string passwordVal = "", 
    string memberIDVal = "", 
    string fullnameVal = "", 
    int creditPointVal = 0, 
    string phoneNumberVal = "", 
    string emailVal = "",
    string homeAddressVal = "", 
    availableCity cityVal = availableCity::SaiGon, 
    bool availableStatusVal = false,
    bool isResetPasswordVal = false, 
    vector<Skill*> skillsVal = {}, 
    vector<Availability*> availabilityVal = {}, 
    vector<string> blockedUsersVal = {}, 
    vector<Request*> sendingRequestsVal = {}, 
    vector<Request*> receivingRequestsVal = {}, 
    vector<Review*> reviewsVal = {})
    : User(usernameVal, passwordVal), 
    memberID(memberIDVal), 
    fullname(fullnameVal), 
    creditPoint(creditPointVal), 
    phoneNumber(phoneNumberVal), 
    email(emailVal),
    homeAddress(homeAddressVal), 
    city(cityVal), 
    availableStatus(availableStatusVal), 
    isResetPassword(isResetPasswordVal),
    skills(skillsVal), 
    availability(availabilityVal), 
    blockedUsers(blockedUsersVal), 
    sendingRequests(sendingRequestsVal),
    receivingRequests(receivingRequestsVal), 
    reviews(reviewsVal) {}

void Member::setAvailableStatus(bool status) {
    availableStatus = status;
}

void Member::blockMember(Member &member) {
    blockedUsers.push_back(member.getMemberId());
    cout << "Block member " << member.getMemberId() << " successfully!\n";
}

void Member::unblockMember(Member &member) {
    for (int i = 0; i < blockedUsers.size(); i++) {
        if (blockedUsers[i] == member.getMemberId()) {
            blockedUsers.erase(blockedUsers.begin() + i);
            break;
        }
    }
    cout << "Unblock member " << member.getMemberId() << " successfully!\n";
}

void Member::creditsTopUp(int amount) {
    creditPoint += amount;
}

void Member::sendRequest(Request &request) {
    sendingRequests.push_back(&request);
}

void Member::receiveRequest(Request &request) {
    receivingRequests.push_back(&request);
}

void Member::addAvailability() {
    cout << "\n---------- Add Availability ----------\n";
    // Unavailable for member that not have any skills
    if (skills.size() == 0) {
        cout << "You have to add at least 1 skill to add availability!\n";
        return;
    }
    string userID = memberID;
    vector<Skill*> performedSkills;
    int pointPerHour;
    double minHostRating;
    
    // Create TimePeriod
    string startDate, startTime;
    string endDate, endTime;
    int startHour, endHour;
    int startMinute, endMinute;

    startDate = InputValidator::getDate("Enter your start date (dd/mm/yyyy): ");
    startTime = InputValidator::getTime("Enter your start time (hh:mm): ");
    endDate = InputValidator::getDate("Enter your end date (dd/mm/yyyy): ");
    endTime = InputValidator::getTime("Enter your end time (hh:mm): ");

    startHour = Converter::stringToInteger(startTime.substr(0, 2));
    startMinute = Converter::stringToInteger(startTime.substr(3, 2));
    endHour = Converter::stringToInteger(endTime.substr(0, 2));
    endMinute = Converter::stringToInteger(endTime.substr(3, 2));

    Time time1(startDate, startHour, startMinute);
    Time time2(endDate, endHour, endMinute);
    TimePeriod* timePeriod = new TimePeriod(time1, time2);

    // Create pointPerHour & minHostRating
    pointPerHour = InputValidator::getInt("Enter your point per hour: ");
    minHostRating = InputValidator::getDouble("Enter your min host rating: "); 

    // Create performedSkills
    cout << "You have to choose at least 1 skill to perform: \n";
    for (int i = 0; i < skills.size(); i++) {
        cout << i + 1 << ". " << skills[i]->getName() << "\n";
    } 
    while (true) {
        int choice = InputValidator::getInt("Enter a choice: ");
        if (choice < 1 || choice > skills.size()) {
            cout << "Invalid choice. Please enter again!\n";
            continue;
        }
        // Stop if member has 1 skill 
        performedSkills.push_back(skills[choice - 1]);
        if (skills.size() < 2) {
            break;
        }
        if (performedSkills.size() == skills.size()) {
            break;
        }
        // ask member if they want to add more skill if there skills are more than 1
        bool isAddSkill = InputValidator::getBool("Do you want to add more skill? (yes/no): ");
        if (!isAddSkill) {
            break;
        }
    }
    // Create availability
    Availability* availability = new Availability(timePeriod, performedSkills, pointPerHour, minHostRating,userID);
    this->availability.push_back(availability);
    cout << "Add availability successfully!\n";
}

void Member::removeAvailability() {
    cout << "\n---------- Remove Availability ----------\n";
    if (availability.size() == 0) {
        cout << "You have no availability to remove!\n";
        return;
    }
    // Prompt user input and find the selected availability
    Availability *selectedAvailability;
    bool isValidSession = false;
    while (!isValidSession) {
        int session = InputValidator::getInt("Enter the session that you want to delete the availability: ");
        if (session < 1 || session > availability.size()) {
            cout << "Invalid session. Please enter again!\n";
            continue;
        }
        selectedAvailability = availability[session - 1];
        isValidSession = true;
    }
    
    // Delete the selected availability
    for (int i = 0; i < availability.size(); i++) {
        if (availability[i] == selectedAvailability) {
            availability.erase(availability.begin() + i);
            break;
        }
    }
    cout << "Remove availability successfully!\n";
}

void Member::updateAvailability(Request &request, Availability &prevAvailability) {
    TimePeriod* requestPeriod = request.getRequestedTime();
    TimePeriod* availabilityPeriod = prevAvailability.getAvailableTime();
    // Calculate the minutes between 2 time periods
    int minutesBetweenStartTime = requestPeriod->getStartTime().getMinutesBetween(availabilityPeriod->getStartTime());
    int minutesBetweenEndTime = availabilityPeriod->getEndTime().getMinutesBetween(requestPeriod->getEndTime());
    
    // Check if the minutes between 2 time periods is greater than 60 minutes
    if (minutesBetweenStartTime >= 60) {
        // Create new Availability
        TimePeriod* newTimePeriod = new TimePeriod(
            availabilityPeriod->getStartTime(), 
            requestPeriod->getStartTime()
        );
        Availability* newAvailability = new Availability(
            newTimePeriod, 
            prevAvailability.getPerformedSkills(), 
            prevAvailability.getPointPerHour(), 
            prevAvailability.getMinHostRating(), 
            prevAvailability.getMemberID()
        );
        availability.push_back(newAvailability);
    } 
    if (minutesBetweenEndTime >= 60) {
        // Create new Availability
        TimePeriod* newTimePeriod = new TimePeriod(
            requestPeriod->getEndTime(), 
            availabilityPeriod->getEndTime()
        );
        Availability* newAvailability = new Availability(
            newTimePeriod, 
            prevAvailability.getPerformedSkills(), 
            prevAvailability.getPointPerHour(), 
            prevAvailability.getMinHostRating(), 
            prevAvailability.getMemberID()
        );
        availability.push_back(newAvailability);
    }

    // Find and delete the previous Availability 
    for (int i = 0; i < availability.size(); i++) {
        if (availability[i] == &prevAvailability) {
            availability.erase(availability.begin() + i);
            break;
        }
    }
    cout << "Your availabilities has been updated!\n";
}

void Member::addReview(Review &review) {
    reviews.push_back(&review);
}

string Member::getMemberId() {
    return memberID;
}

string Member::getFullname() {
    return fullname; 
}

int Member::getCreditPoint() {
    return creditPoint;
}

void Member::setCreditPoint(int creditPoint) {
    this->creditPoint = creditPoint;
}

string Member::getPhoneNumber() {
    return phoneNumber;
}

string Member::getEmail() {
    return email;
}

bool Member::getAvailableStatus() {
    return availableStatus;
}

bool Member::getIsResetPassword() {
    return isResetPassword;
}

void Member::setIsResetPassword(bool isResetPassword) {
    this->isResetPassword = isResetPassword;
}

string Member::getAvailableCity() { 
    return city == availableCity::HaNoi ? "Ha Noi" : "Sai Gon";
}

string Member::getHomeAddress() {
    return homeAddress;
}

double Member::getHostRating() {
    vector<Review*> hostReviews = {};
    for (auto &review : reviews) {
        if (review->getType() == "Host") {
            hostReviews.push_back(review);
        }
    }

    // If member have no host review yet, the default rating is 0
    if (hostReviews.size() == 0) {
        return 0;
    }

    double totalRating = 0;
    for (auto &review : hostReviews) {
        totalRating += review->getRatingScore();
    }
    return totalRating / hostReviews.size();
}

double Member::getSupporterRating() {
    vector<Review*> supporterReviews = {};
    for (auto &review : reviews) {
        if (review->getType() == "Supporter") {
            supporterReviews.push_back(review);
        }
    }

    // If member have no supporter review yet, the default rating is 0
    if (supporterReviews.size() == 0) {
        return 0;
    }

    double totalRating = 0;
    for (auto &review : supporterReviews) {
        totalRating += review->getRatingScore();
    }
    return totalRating / supporterReviews.size();
}

vector<Availability*> Member::getAvailability() {
    return availability;
}

vector<Skill*> Member::getSkill() {
    return skills;
}

vector<Request*> Member::getSendingRequest() {
    return sendingRequests;
}

vector<Request*> Member::getReceivingRequest() {
    return receivingRequests;
}

vector<Review*> Member::getReview() {
    return reviews;
}

vector<string> Member::getBlockedUsers() {
    return blockedUsers;
}

void Member::showInfo() {
    // Show member basic information
    size_t longestFieldLength = 12;
    vector<string> fields = {
        fullname,
        email,
        homeAddress,
        Converter::blockedUsersToString(blockedUsers),
    };

    for (auto &field : fields) {
        if (field.length() > longestFieldLength) {
            longestFieldLength = field.length();
        }
    }

    // Print the title
    string title = "Your Information";
    size_t titleLength = title.length() + 2;
    size_t tableWidth = longestFieldLength + 23;
    size_t leftPadding = (tableWidth - titleLength) / 2;
    size_t rightPadding = tableWidth - titleLength - leftPadding;

    cout << "\n";
    cout << string(leftPadding, '-') << " " << title << " " << string(rightPadding, '-') << "\n";

    // Print a line separator
    cout << string(tableWidth, '-') << "\n";

    // Print the member information
    string statusString = availableStatus ? "Available" : "Unavailable";
    cout << std::left << "| " << std::setw(16) << "Member ID" << " | " << std::setw(longestFieldLength) << memberID << " |\n";
    cout << "| " << std::setw(16) << "Fullname" << " | " << std::setw(longestFieldLength) << fullname << " |\n";
    cout << "| " << std::setw(16) << "Username" << " | " << std::setw(longestFieldLength) << User::getUsername() << " |\n";
    cout << "| " << std::setw(16) << "Password" << " | " << std::setw(longestFieldLength) << User::getPassword() << " |\n";
    cout << "| " << std::setw(16) << "Email" << " | " << std::setw(longestFieldLength) << email << " |\n";
    cout << "| " << std::setw(16) << "Phone Number" << " | " << std::setw(longestFieldLength) << phoneNumber << " |\n";
    cout << "| " << std::setw(16) << "Home Address" << " | " << std::setw(longestFieldLength) << homeAddress << " |\n";
    cout << "| " << std::setw(16) << "City" << " | " << std::setw(longestFieldLength) << getAvailableCity() << " |\n";
    cout << "| " << std::setw(16) << "Available Status" << " | " << std::setw(longestFieldLength) << statusString << " |\n";
    cout << "| " << std::setw(16) << "Credit Point" << " | " << std::setw(longestFieldLength) << creditPoint << " |\n";
    cout << "| " << std::setw(16) << "Host Rating" << " | " << std::setw(longestFieldLength) << std::fixed << std::setprecision(1) << getHostRating() << " |\n";
    cout << "| " << std::setw(16) << "Supporter Rating" << " | " << std::setw(longestFieldLength) << std::fixed << std::setprecision(1) << getSupporterRating() << " |\n";
    cout << "| " << std::setw(16) << "Blocked Users" << " | " << std::setw(longestFieldLength) << Converter::blockedUsersToString(blockedUsers) << " |\n";

    // Print a line separator
    cout << string(tableWidth, '-') << "\n";

    // Print the skills information
    if (skills.size() == 0) {
        cout << "\nYou have no skill to display!\n";
    } else {
        TableGenerator::generateSkillTable("Your Skills", skills);
    }

    // Print the availability information
    if (availability.size() == 0) {
        cout << "\nYou have no availability to display!\n";
    } else {
        TableGenerator::generateAvailabilityTable("Your Availabilities", availability);
    }

    // Print the sending request information
    if (sendingRequests.size() == 0) {
        cout << "\nYou have no sending request to display!\n";
    } else {
        TableGenerator::generateRequestTable("Your Sending Requests", sendingRequests);
    }

    // Print the receiving request information
    if (receivingRequests.size() == 0) {
        cout << "\nYou have no receiving request to display!\n";
    } else {
        TableGenerator::generateRequestTable("Your Receiving Requests", receivingRequests);
    }

    // Print the review information
    if (reviews.size() == 0) {
        cout << "\nYou have no review to display!\n";
    } else {
        TableGenerator::generateReviewTable("Your Reviews", reviews);
    }
}

Member::~Member() {
    for (auto &skill : skills) {
        delete skill;
    }
    for (auto &availability : availability) {
        delete availability;
    }
    for (auto &request : sendingRequests) {
        delete request;
    }
    for (auto &request : receivingRequests) {
        delete request;
    }
    for (auto &review : reviews) {
        delete review;
    }
}
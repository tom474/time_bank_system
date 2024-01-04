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

void Member::setAvailableStatus() {

}

void Member::blockMember(Member &member) {
    blockedUsers.push_back(member.getMemberId());
    cout << "Block member" << member.getMemberId() << "successfully!\n\n";
}

void Member::unblockMember(Member &member) {
    for (int i = 0; i < blockedUsers.size(); i++) {
        if (blockedUsers[i] == member.getMemberId()) {
            blockedUsers.erase(blockedUsers.begin() + i);
            break;
        }
    }
    cout << "Unblock member" << member.getMemberId() << "successfully!\n\n";
}

void Member::creditsTopUp(int amount) {

}

void Member::viewRequest() {

}

void Member::sendRequest(Request &request) {
    sendingRequests.push_back(&request);
}

void Member::receiveRequest(Request &request) {
    receivingRequests.push_back(&request);
}

void Member::acceptRequest(Request &request) {

}

void Member::rejectRequest(Request &request) {

}

void Member::rateSupporter() {

}

void Member::rateHost() {

}

void Member::addAvailability() {
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
            cout << "You only have 1 skill. Cannot add more skills.\n";
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

string Member::getMemberId() {
    return memberID;
}

string Member::getFullname() {
    return fullname; 
}

int Member::getCreditPoint() {
    return creditPoint;
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

// TESTING PURPOSE
void Member::showInfo() {
    cout << "Member ID: " << memberID << "\n";
    cout << "Fullname: " << fullname << "\n";
    cout << "Credit Point: " << creditPoint << "\n";
    cout << "Phone Number: " << phoneNumber << "\n";
    cout << "Email: " << email << "\n";
    cout << "Home Address: " << homeAddress << "\n";
    cout << "City: " << (city == availableCity::HaNoi ? "Ha Noi" : "Sai Gon") << "\n";
    cout << "Available Status: " << Converter::boolToString(availableStatus) << "\n";
    cout << "Reset Password: " << Converter::boolToString(isResetPassword) << "\n";
    cout << "Skills:" << "\n";
    for (auto &skill : skills) {
        cout << "- " << skill->getName() << ": " << skill->getDescription() << "\n";
    }

    cout << "Availability:" << "\n";
    for (auto &avail : availability) {
        cout << "- Available Time: " << avail->getAvailableTime()->getStartTime().getDate() << " "
                  << avail->getAvailableTime()->getStartTime().getHour() << ":"
                  << avail->getAvailableTime()->getStartTime().getMinute() << " - "
                  << avail->getAvailableTime()->getEndTime().getDate() << " "
                  << avail->getAvailableTime()->getEndTime().getHour() << ":"
                  << avail->getAvailableTime()->getEndTime().getMinute() << "\n";

        cout << "- Performed Skills:" << "\n";
        for (auto &skill : avail->getPerformedSkills()) {
            cout << "- " << skill->getName() << "\n";
        }
    }

    cout << "Blocked Users:" << "\n";
    for (auto &user : blockedUsers) {
        cout << "- " << user << "\n";
    }

    cout << "Sending Requests:" << "\n";
    for (auto &req : sendingRequests) {
        cout << "- Request ID: " << req->getRequestID() << ", Status: " << req->getStatus() << "\n";
    }

    cout << "Receiving Requests:" << "\n";
    for (auto &req : receivingRequests) {
        cout << "- Request ID: " << req->getRequestID() << ", Status: " << req->getStatus() << "\n";
    }

    cout << "Reviews:" << "\n";
    for (auto &review : reviews) {
        cout << "- Review ID: " << review->getReviewID() << ", Rating: " << review->getRatingScore()
                  << ", Comment: " << review->getComment() << "\n";
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
#include "Member.h"

#include <iostream>

using std::cout;

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
    vector<Skill*> skillsVal = {}, 
    vector<Availability*> availabilityVal = {}, 
    vector<string> blockedUsersVal = {}, 
    vector<Request*> requestsVal = {}, 
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
    skills(skillsVal), 
    availability(availabilityVal), 
    blockedUsers(blockedUsersVal), 
    requests(requestsVal), 
    reviews(reviewsVal) {}

void Member::setAvailableStatus() {

}

void Member::login() {

}

void Member::logout() {

}

void Member::blockUser(User &user) {

}

void Member::unblockUser(User &user) {

}

void Member::creditsTopUp(int amount) {

}

void Member::searchSupporter() {

}

void Member::bookSupporter() {

}

void Member::viewRequest() {

}

void Member::acceptRequest(Request &request) {

}

void Member::rejectRequest(Request &request) {

}

void Member::rateSupporter() {

}

void Member::rateHost() {

}

void Member::addAvailability(Availability &availability) {

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

string Member::boolToString(bool status) {
    return status ? "true" : "false";
}
string Member::getAvailableCity() { 
    return city == availableCity::HaNoi ? "Ha Noi" : "Sai Gon";
}

string Member::getHomeAddress() {
    return homeAddress;
}
vector<Availability*> Member::getAvailability() {
    return availability;
}

vector<Skill*> Member::getSkill() {
    return skills;
}

vector<Request*> Member::getRequest() {
    return requests;
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
    cout << "Available Status: " << boolToString(availableStatus) << "\n";

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

    cout << "Requests:" << "\n";
    for (auto &req : requests) {
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
    for (auto &request : requests) {
        delete request;
    }
    for (auto &review : reviews) {
        delete review;
    }
}
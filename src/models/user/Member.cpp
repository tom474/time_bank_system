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
    skills(skillsVal), 
    availability(availabilityVal), 
    blockedUsers(blockedUsersVal), 
    sendingRequests(sendingRequestsVal),
    receivingRequests(receivingRequestsVal), 
    reviews(reviewsVal) {}

void Member::setAvailableStatus() {

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

bool Member::getIsResetPassword() {
    return isResetPassword;
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
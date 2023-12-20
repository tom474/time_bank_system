#include "Member.h"

#include <iostream>

Member::Member(
    string usernameVal = "", 
    string passwordVal = "", 
    string memberIDVal = "", 
    string fullnameVal = "", 
    int creditPointVal = 0, 
    string phoneNumberVal = "", 
    string homeAddressVal = "", 
    availableCity cityVal = availableCity::SaiGon, 
    bool availableStatusVal = false, 
    vector<Skill*> skillsVal = {}, 
    vector<Availability*> availabilityVal = {}, 
    vector<Member*> blockedUsersVal = {}, 
    vector<Request*> requestsVal = {}, 
    vector<Review*> reviewsVal = {})
    : User(usernameVal, passwordVal), 
    memberID(memberIDVal), 
    fullname(fullnameVal), 
    creditPoint(creditPointVal), 
    phoneNumber(phoneNumberVal), 
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

void Member::showInfo() {

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
availableCity Member::getAvailableCity() { 
    return city;
}
string Member::getAvailableCityName(availableCity availableCity) {
    return availableCity == HaNoi ? "Ha Noi" : "Ho Chi Minh";
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

vector<Member*> Member::getBlockedUsers() {
    return blockedUsers;
}

Member::~Member() {
    for (auto &skill : skills) {
        delete skill;
    }
    for (auto &availability : availability) {
        delete availability;
    }
    for (auto &user : blockedUsers) {
        delete user;
    }
    for (auto &request : requests) {
        delete request;
    }
    for (auto &review : reviews) {
        delete review;
    }
}
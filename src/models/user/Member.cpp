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
    vector<User*> blockedUsersVal = {}, 
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
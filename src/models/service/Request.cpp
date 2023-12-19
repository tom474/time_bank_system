#include "./Request.h"

#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

Request::Request(
    string requestIDVal = "", 
    string hostIDVal = "", 
    string supporterIDVal= "", 
    TimePeriod *desiredTimeVal = nullptr, 
    vector<Skill*> requestedSkillsVal = {}, 
    requestStatus statusVal = requestStatus::Pending) 
    : requestID(requestIDVal), 
    hostID(hostIDVal), 
    supporterID(supporterIDVal), 
    desiredTime(desiredTimeVal), 
    requestedSkills(requestedSkillsVal), 
    status(statusVal) {}

Request::~Request() {
    delete desiredTime;
    for (auto skill : requestedSkills) {
        delete skill;
    }
}

string Request::getRequestID() {
    return requestID;
}

TimePeriod* Request::getRequestedTime() {
    return desiredTime;
}

string Request::getHostID() {
    return hostID;
}

string Request::getSupporterID() {
    return supporterID;
}

vector<Skill*> Request::getRequestedSkills() {
    return requestedSkills;
}

requestStatus Request::getStatus() {
    return status;
}
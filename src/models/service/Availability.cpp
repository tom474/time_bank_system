#include "./Availability.h"
#include "./Skill.h"

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

Availability::Availability() {}

Availability::Availability(
    TimePeriod *availableTimeVal = nullptr,
    vector<Skill*> performedSkillsVal = {},
    int pointPerHourVal = 0,
    double minHostRatingVal = 0.0,
    string memberIDVal = "")
    : availableTime(availableTimeVal),
    performedSkills(performedSkillsVal),
    pointPerHour(pointPerHourVal),
    minHostRating(minHostRatingVal),
    memberID(memberIDVal) {}

Availability::~Availability() {
    delete availableTime;
    for (auto &skill : performedSkills) {
        delete skill;
    }
}

string Availability::getMemberID() {
    return memberID;
}

TimePeriod *Availability::getAvailableTime() {
    return availableTime;
}

int Availability::getPointPerHour() {
    return pointPerHour;
}

double Availability::getMinHostRating() {
    return minHostRating;
}

vector<Skill*> Availability::getPerformedSkills() {
    return performedSkills;
}
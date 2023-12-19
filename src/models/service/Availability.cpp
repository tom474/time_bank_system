#include "./Availability.h"

#include <iostream>
#include <vector>

using std::cout;
using std::string;
using std::cin;
using std::endl;

Availability::Availability(
    TimePeriod *availableTimeVal = nullptr, 
    vector<Skill*> performedSkillsVal = {},
    int pointPerHourVal = 0,
    double minHostRatingVal = 0.0)
    : availableTime(availableTimeVal),
    performedSkills(performedSkillsVal),
    pointPerHour(pointPerHourVal),
    minHostRating(minHostRatingVal) {}

Availability::~Availability() {
    delete availableTime;
    for (auto &skill : performedSkills) {
        delete skill;
    }
}

TimePeriod* Availability::getAvailableTime() {
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
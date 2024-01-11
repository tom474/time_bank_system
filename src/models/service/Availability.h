#ifndef _AVAILABILITY_H_
#define _AVAILABILITY_H_

#include "../../utils/TimeManager.h"

#include <iostream>
#include <vector>

using std::string;
using std::vector;

class TimePeriod;
class Skill;

class Availability {
    private:
        string memberID;
        TimePeriod *availableTime;
        vector<Skill*> performedSkills;
        int pointPerHour;
        double minHostRating;

    public:
        Availability();
        Availability(TimePeriod *availableTimeVal, vector<Skill*> performedSkillsVal, int pointPerHourVal, double minHostRatingVal, string memberIDVal);
        string getMemberID();
        TimePeriod *getAvailableTime();
        int getPointPerHour();
        double getMinHostRating();
        vector<Skill *> getPerformedSkills();
        ~Availability();
};

#endif  // _AVAILABILITY_H_
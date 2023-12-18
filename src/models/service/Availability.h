#ifndef _AVAILABILITY_H_
#define _AVAILABILITY_H_

#include "../../utils/TimeManagement.h"
#include <iostream>
#include <vector>

using std::string;
using std::vector;

class TimePeriod;
class Skill;
class Availability {
    private:
        TimePeriod* availableTime;
        vector<Skill*> performedSkills;
        int pointPerHour;
        double minHostRating;
    public:
        Availability(TimePeriod* availableTimeVal, vector<Skill*> performedSkillsVal, int pointPerHourVal, double minHostRatingVal);
        TimePeriod* getAvailableTime();
        int getPointPerHour();
        double getMinHostRating();
        vector<Skill*> getPerformedSkills();
        ~Availability();
};

#endif
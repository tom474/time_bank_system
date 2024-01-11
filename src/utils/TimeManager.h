#ifndef _TIME_MANAGER_H_
#define _TIME_MANAGER_H_

#include <iostream>
#include <vector>
#include "math.h"

using std::string;
using std::vector;

class Time {
    private:
        string date;
        int hour;
        int minute;
    public:
        Time(string dateVal, int hourVal, int minuteVal);
        string getDate();
        int getHour();
        int getMinute();
        vector<int> splitDate(string date);
        int compareTime(Time &time);
        int getMinutesBetween(Time time);
        string toString();
};

class TimePeriod {
    private:
        Time startTime;
        Time endTime;
    public:
        TimePeriod(Time startTimeVal, Time endTimeVal);
        Time getStartTime();
        Time getEndTime();
        bool isOverlapsWith(TimePeriod &timeRequest);
        int getHourDuration();
        string toString();
        
};

#endif  // _TIME_MANAGER_H_
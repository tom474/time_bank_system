#ifndef _TIME_MANAGER_H_
#define _TIME_MANAGER_H_

#include <iostream>

using std::string;

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
        bool compareTime(Time &time);
};

class TimePeriod {
    private:
        Time startTime;
        Time endTime;
    public:
        TimePeriod(Time startTimeVal, Time endTimeVal);
        Time getStartTime();
        Time getEndTime();
        bool isOverlapsWith(TimePeriod &timePeriod);
};

#endif
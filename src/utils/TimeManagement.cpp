#include "./TimeManagement.h"
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

Time::Time(string dateVal = "dd/mm/yyyy",int hourVal = 0,int minuteVal = 0) : date(dateVal), hour(hourVal), minute(minuteVal) {
}

string Time::getDate() {
    return date;
}

int Time::getHour() {
    return hour;
}

int Time::getMinute() {
    return minute;
}

bool Time::compareTime(Time &time) {
    return true;
}

TimePeriod::TimePeriod(Time startTime, Time endTime) : startTime(startTime), endTime(endTime) {
};

Time TimePeriod::getStart() {
    return startTime;
}

Time TimePeriod::getEnd() {
    return endTime;
}

bool TimePeriod::isOverlapsWith(TimePeriod &timePeriod) {
    return true;
}
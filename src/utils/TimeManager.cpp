#include "./TimeManager.h"

#include <iostream>
#include <sstream>
#include <vector>

using std::vector;
using std::string;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;

Time::Time(
    string dateVal = "dd/mm/yyyy",
    int hourVal = 0,
    int minuteVal = 0) 
    : date(dateVal), 
    hour(hourVal), 
    minute(minuteVal) {}

string Time::getDate() {
    return date;
}

int Time::getHour() {
    return hour;
}

int Time::getMinute() {
    return minute;
}

int Time::compareTime(Time &time) {
    // Convert date to vector for comparison
    vector<int> date1 = splitDate(date);
    vector<int> date2 = splitDate(time.getDate());

    // Compare year
    if (date1[2] > date2[2]) {
        return 1;
    } else if (date1[2] < date2[2]) {
        return -1;
    }

    // Compare month
    if (date1[1] > date2[1]) {
        return 1;
    } else if (date1[1] < date2[1]) {
        return -1;
    }

    // Compare day
    if (date1[0] > date2[0]) {
        return 1;
    } else if (date1[0] < date2[0]) {
        return -1;
    }

    // Compare hour
    if (hour > time.getHour()) {
        return 1;
    } else if (hour < time.getHour()) {
        return -1;
    }

    // Compare minute
    if (minute > time.getMinute()) {
        return 1;
    } else if (minute < time.getMinute()) {
        return -1;
    }

    return 0; // Dates and times are equal
};

vector<int> Time::splitDate(string date) {
    string tmp;
    vector<int> dateVector;
    stringstream sstr;
    sstr << date;
    while(getline(sstr, tmp, '/')) {
        dateVector.push_back(std::stoi(tmp));
    }
    return dateVector;
};

TimePeriod::TimePeriod(Time startTime, Time endTime) : startTime(startTime), endTime(endTime) {};

Time TimePeriod::getStartTime() {
    return startTime;
};

Time TimePeriod::getEndTime() {
    return endTime;
};

bool TimePeriod::isOverlapsWith(TimePeriod &timeRequest) {
    // Start time of timeRequest should be after the start time of supporter's available time period
    // End time of timeRequest should be before than end time of supporter's available time period
    int isOverlapStart = timeRequest.getStartTime().compareTime(startTime); 
    int isOverlapEnd = timeRequest.getEndTime().compareTime(endTime);

    if ((isOverlapStart >= 0) && (isOverlapEnd <= 0)) {
        return true; 
    } else {
        return false; 
    }
}

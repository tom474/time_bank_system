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

bool Time::compareTime(Time &time) {
    // Convert date to vector for comparison
    vector<int> date1 = sliptDate(this->date);
    vector<int> date2 = sliptDate(time.getDate());
    cout << date1[0] << "/" << date1[1] << "/" << date1[2] << " " << hour << " : " << minute << endl;
    cout << date2[0] <<"/" << date2[1] << "/" << date2[2] << " " << time.hour << " : " << time.minute << endl;
    // Compare year, month, day, hour, and minute
 if (date1[2] > date2[2]) {
        return true;
    } else if (date1[2] < date2[2]) {
        return false;
    }

    if (date1[1] > date2[1]) {
        return true;
    } else if (date1[1] < date2[1]) {
        return false;
    }

    if (date1[0] > date2[0]) {
        return true;
    } else if (date1[0] < date2[0]) {
        return false;
    }

    if (hour > time.getHour()) {
        return true;
    } else if (hour < time.getHour()) {
        return false;
    }

    if (minute > time.getMinute()) {
        return true;
    } else if (minute < time.getMinute()) {
        return false;
    }

    return false; // Dates and times are identical
};

vector<int> Time::sliptDate(string date) {
    string tmp;
    vector<int> dateVector;
    stringstream ss(date);
    while(std::getline(ss,tmp,'/')) {
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

bool TimePeriod::isOverlapsWith(TimePeriod &timePeriod) {
    // start time of timePeriod should be smaller than start time of request
    // end time of timePeriod should be larger than end time of request
    return !timePeriod.getStartTime().compareTime(startTime) && timePeriod.getEndTime().compareTime(endTime);
}

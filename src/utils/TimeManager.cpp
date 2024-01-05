#include "./TimeManager.h"

#include <iostream>
#include <sstream>
#include <vector>

using std::vector;
using std::string;
using std::stringstream;
using std::cout;
using std::cin;

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

int Time::getMinutesBetween(Time time) {
    int totalMinutes = 0;
    // Convert date to vector format
    vector<int> date1 = splitDate(date);
    vector<int> date2 = splitDate(time.getDate());

    // get the hour between year
    totalMinutes += (date1[2] - date2[2]) * 365 * 24 * 60;
    // get the hour between months
    totalMinutes += (date1[1] - date2[1]) * 30 * 24 * 60;
    // get total hour between days
    totalMinutes += (date1[0] - date2[0]) * 24 * 60;
    // get total hour between hours
    totalMinutes += (hour - time.getHour()) * 60;
    // get total hour between minutes
    totalMinutes += minute - time.getMinute();
    return totalMinutes;
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

string Time::toString() {
    // Format start time and end time
    string hourStr, minuteStr;
    if (hour < 10) {
        hourStr = "0" + std::to_string(hour);
    } else {
        hourStr = std::to_string(hour);
    }
    if (minute < 10) {
        minuteStr = "0" + std::to_string(minute);
    } else {
        minuteStr = std::to_string(minute);
    }
    string timeString = hourStr + ":" + minuteStr + " " + date;
    return timeString;
}

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

int TimePeriod::getHourDuration() {
    int hourDuration = 0;

    // Calculate the duration in hours if start date and end date are the same
    if (startTime.getDate() == endTime.getDate()) {
        hourDuration = endTime.getHour() - startTime.getHour();
        if (endTime.getMinute() > startTime.getMinute()) {
            hourDuration += 1;
        }
    } else {
        // Calculate the duration in hours for different dates
        vector<int> startDate = startTime.splitDate(startTime.getDate());
        vector<int> endDate = endTime.splitDate(endTime.getDate());

        // Calculate the duration in years
        int yearDuration = endDate[2] - startDate[2];

        // Calculate the duration in months
        int monthDuration = endDate[1] - startDate[1];

        // Calculate the duration in days
        int dayDuration = endDate[0] - startDate[0];

        // Calculate the duration in hours
        hourDuration = yearDuration * 365 * 24 + monthDuration * 30 * 24 + dayDuration * 24;

        // Adjust the duration based on the time of the start and end dates
        hourDuration -= startTime.getHour();
        hourDuration += endTime.getHour();
        if (endTime.getMinute() > startTime.getMinute()) {
            hourDuration += 1;
        }
    }

    return hourDuration;
}

string TimePeriod::toString() {
    return "Start: " + startTime.toString() + ", End: " + endTime.toString();
}
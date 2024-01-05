#ifndef _REQUEST_H_
#define _REQUEST_H_

#include "../../utils/TimeManager.h"

#include <iostream>
#include <vector>

using std::string;
using std::vector;

enum requestStatus {
    Pending,
    Accepted,
    Rejected
};

class TimePeriod;
class Skill;

class Request {
    private:
        string requestID;
        string hostID;
        string supporterID;
        TimePeriod *desiredTime;
        vector<Skill*> requestedSkills;
        requestStatus status;
    public:
        Request();
        Request(string requestIDVal, string hostIDVal, string supporterIDVal, TimePeriod *desiredTimeVal, vector<Skill*> requestedSkillsVal, requestStatus statusVal);
        string getRequestID();
        TimePeriod* getRequestedTime();
        string getHostID();
        string getSupporterID();
        vector<Skill*> getRequestedSkills();
        string getStatus();
        void setStatus(requestStatus newStatus);
        ~Request();
};

#endif  // _REQUEST_H_
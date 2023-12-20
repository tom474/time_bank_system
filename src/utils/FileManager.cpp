#include "./FileManager.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::string;
using std::vector;
using std::fstream;
using std::cerr;
using std::endl;

#define ADMIN_DATABASE "../data/admin.csv"
#define MEMBER_DATABASE "../data/member.csv"
#define AVAILABILITY_DATABASE "../data/availability.csv"
#define REQUEST_DATABASE "../data/request.csv"
#define REVIEW_DATABASE "../data/review.csv"
#define SKILL_DATABASE "../data/skill.csv"

void saveMemberDatabase(vector<Member*> members) {
    fstream memberFile;
    memberFile.open(MEMBER_DATABASE, std::ios::out);
    if (!memberFile.is_open()) {
        cerr << "Fail to create/open member.csv file" << endl;   
    }
    for (auto member : members) {
        memberFile 
            << member->getMemberId() << "," 
            << member->getFullname() << "," 
            << member->getCreditPoint() << "," 
            << member->getPhoneNumber() << "," 
            << member->getEmail() << "," 
            << member->getHomeAddress() << "," 
            << member->getAvailableCity() << "," 
            << member->boolToString(member->getAvailableStatus());
        for (auto blockedUser : member->getBlockedUsers()) {
            memberFile << "," << blockedUser->getMemberId();
        }
        memberFile << endl;
        saveAvailabilityDatabase(member->getAvailability());
        saveRequestDatabase(member->getRequest());
        saveReviewDatabase(member->getReview());
        saveSkillDatabase(member->getSkill());
    }
    memberFile.close();
}

void saveAvailabilityDatabase(vector<Availability*> availabilities) {
    fstream availabilityFile;
    availabilityFile.open(AVAILABILITY_DATABASE, std::ios::out);
    if (!availabilityFile.is_open()) {
        cerr << "Fail to create/open availability.csv file" << endl;   
    }
    for (auto availability : availabilities) {
        availabilityFile 
            << availability->getMemberID() << "," 
            << availability->getPointPerHour() << "," 
            << availability->getMinHostRating() << ","
            << availability->getAvailableTime()->getStartTime().getDate() << ","
            << availability->getAvailableTime()->getStartTime().getHour() << ","
            << availability->getAvailableTime()->getStartTime().getMinute() << ","
            << availability->getAvailableTime()->getEndTime().getDate() << ","
            << availability->getAvailableTime()->getEndTime().getHour() << ","
            << availability->getAvailableTime()->getEndTime().getMinute();
        for (auto skill : availability->getPerformedSkills()) {
            availabilityFile << "," << skill->getName();
        }
        availabilityFile << endl;
    }
    availabilityFile.close();
}

void saveRequestDatabase(vector<Request*> requests) {
    fstream requestFile;
    requestFile.open(REQUEST_DATABASE, std::ios::out);

    if (!requestFile.is_open()) {
        cerr << "Fail to create/open request.csv file!\n"; 
        return;
    }

    for (auto req : requests) {
        if (req->getStatus() != "Rejected") {
            requestFile 
                << req->getRequestID() << ","
                << req->getSupporterID() << ","
                << req->getHostID() << ","
                << req->getRequestedTime()->getStartTime().getDate() << ","
                << req->getRequestedTime()->getStartTime().getHour() << "," 
                << req->getRequestedTime()->getStartTime().getMinute() << "," 
                << req->getRequestedTime()->getEndTime().getDate() << "," 
                << req->getRequestedTime()->getEndTime().getHour() << "," 
                << req->getRequestedTime()->getEndTime().getMinute() << "," 
                << req->getStatus();
            for (auto skill : req->getRequestedSkills()) {
                requestFile << "," << skill->getName();
            }
            requestFile << endl;
        }
    }
    requestFile.close();
}

void saveReviewDatabase(vector<Review*> reviews) {
    fstream reviewFile;
    reviewFile.open(REVIEW_DATABASE, std::ios::out);

    if (!reviewFile.is_open()) {
        cerr << "Fail to create/open review.csv file!\n"; 
        return;
    }

    for (auto review : reviews) {
        reviewFile 
            << review->getReviewID() << ","
            << review->getReviewedID() << ","
            << review->getReviewerID() << ","
            << review->getType() << ","
            << review->getRatingScore() << ","
            << review->getComment();
        reviewFile << endl;
    }
    reviewFile.close();
}

void saveSkillDatabase(vector<Skill*> skills) {
    fstream skillFile;
    skillFile.open(SKILL_DATABASE, std::ios::out);

    if (!skillFile.is_open()) {
        cerr << "Fail to create/open skill.csv file!\n"; 
        return;
    }

    for (auto skill : skills) {
        skillFile 
            << skill->getName() << ","
            << skill->getDescription() << ","
            << skill->getMemberID();
        for (auto ratingScore : skill->getRatingScore()) {
            skillFile << "," << ratingScore;
        }
        skillFile << endl;
    }
    skillFile.close();
}

Admin loadAdminDatabase() {
    fstream adminFile;
    Admin admin;
    adminFile.open(ADMIN_DATABASE, std::ios::in);
    if (!adminFile.is_open()) {
        cerr << "Fail to create/open " << ADMIN_DATABASE << " file" << endl;
    }
    string username, password;
    while (true) {
        getline(adminFile, username, ',');
        getline(adminFile, password, ',');
        if (username != "" || password != "") {
            break;
        }
    }
    admin.setUsername(username);
    admin.setPassword(password);
    adminFile.close();
    return admin;
}

vector<Member*> loadMemberDatabase() {
    vector<Availability*> availabilities = loadAvailabilityDatabase();
    vector<Request*> requests = loadRequestDatabase();
    vector<Review*> reviews = loadReviewDatabase();
    vector<Skill*> skills = loadSkillDatabase();
    vector<Member*> members = {};
    
    fstream memberFile;
    memberFile.open(MEMBER_DATABASE, std::ios::in);
    if (!memberFile.is_open()) {
        cerr << "Fail to create/open" << MEMBER_DATABASE << " file" << endl;
    }
    
    while(true) {
        // MemberID
        string memberID;
        getline(memberFile, memberID, ',');
        if (memberID == "") {
            break;
        }

        // Username
        string username;
        getline(memberFile, username, ',');
        
        // Password
        string password;
        getline(memberFile, password, ',');
        
        // Fullname
        string fullname;
        getline(memberFile, fullname, ',');
        
        // CreditPoint
        string creditPoint;
        getline(memberFile, creditPoint, ',');
        
        // PhoneNumber
        string phoneNumber;
        getline(memberFile, phoneNumber, ',');
        
        // Email
        string email;
        getline(memberFile, email, ',');
        
        // HomeAddress
        string homeAddress;
        getline(memberFile, homeAddress, ',');
        
        // City
        string city;
        getline(memberFile, city, ',');
        
        // AvailableStatus
        string availableStatus;
        getline(memberFile, availableStatus, ',');
        
        // Availability
        vector<Availability*> memberAvailabilities = {};
        for (auto availability : availabilities) { 
            if (availability->getMemberID() == memberID) {
                memberAvailabilities.push_back(availability);
            }
        }
        
        // Skill
        vector<Skill*> memberSkills = {};
        for (auto skill : skills)  {
            if (skill->getMemberID() == memberID) {
                memberSkills.push_back(skill);
            }
        }
        
        // Request 
        vector<Request*> memberRequests = {};
        for (auto request : requests) {
            if (request->getSupporterID() == memberID) {
                memberRequests.push_back(request);
            }
        }
        
        // Review
        vector<Review*> memberReviews = {};
        for (auto review : reviews) {
            if (review->getReviewedID() == memberID) {
                memberReviews.push_back(review);
            }
        }
        
        // Create new Member
        Member *member = new (std::nothrow) Member(
            username, 
            password, 
            memberID, 
            fullname, 
            stoi(creditPoint), 
            phoneNumber, 
            email, 
            homeAddress, 
            city == "Ha Noi" ? availableCity::HaNoi : availableCity::SaiGon, 
            availableStatus == "true" ? true : false, 
            memberSkills, 
            memberAvailabilities, 
            {}, 
            memberRequests, 
            memberReviews
        );
        members.push_back(member);        
    }   
    return members;
}

vector<Availability*> loadAvailabilityDatabase() {
    vector<Skill*> skills = loadSkillDatabase();
    vector<Availability*> availabilities = {};
    fstream availabilityFile;
    availabilityFile.open(AVAILABILITY_DATABASE, std::ios::in);
    if (!availabilityFile.is_open()) {
        cerr << "Fail to create/open" << AVAILABILITY_DATABASE << " file" << endl;
    }
    while (true) {
        // MemberID
        string memberID;
        getline(availabilityFile, memberID, ',');
        if (memberID == "") {
            break;
        }
        
        // Point per hour
        string pointPerHour;
        getline(availabilityFile, pointPerHour, ',');
        
        // Min host rate
        string minHostRating;
        getline(availabilityFile, minHostRating, ',');
        
        // TimePeriod
        string startDate, startHourStr, startMinuteStr;
        getline(availabilityFile, startDate, ',');
        getline(availabilityFile, startHourStr, ',');
        getline(availabilityFile, startMinuteStr, ',');
        int startHour = std::stoi(startHourStr);
        int startMinute = std::stoi(startMinuteStr);
        string endDate, endHourStr, endMinuteStr;
        getline(availabilityFile, endDate, ',');
        getline(availabilityFile, endHourStr, ',');
        getline(availabilityFile, endMinuteStr, ',');
        int endHour = std::stoi(endHourStr);
        int endMinute = std::stoi(endMinuteStr);
        Time startTime(startDate, startHour, startMinute), endTime(endDate, endHour, endMinute);
        TimePeriod *desiredTime = new (std::nothrow) TimePeriod(startTime, endTime);
        
        // Performed skills
        vector<Skill*> performedSkills = {};
        for (auto skill : skills) { 
            if (skill->getMemberID() == memberID) {
                performedSkills.push_back(skill);
            }
        }
        
        // Create new Availability
        Availability *availability = new (std::nothrow) Availability(desiredTime, performedSkills, stoi(pointPerHour), stod(minHostRating), memberID);
        availabilities.push_back(availability);
    }
    return availabilities;
} 
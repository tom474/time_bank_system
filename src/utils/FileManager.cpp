#include "./FileManager.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

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

void FileManager::resetDatabase() {
    fstream myFile;

    myFile.open(MEMBER_DATABASE, std::ios::out);
    if (!myFile.is_open()) {
        cerr << "Fail to reset member.csv file!\n";
    } else {
        myFile << "";
        myFile.close();
    }

    myFile.open(AVAILABILITY_DATABASE, std::ios::out);
    if (!myFile.is_open()) {
        cerr << "Fail to reset availability.csv file!\n";
    } else {
        myFile << "";
        myFile.close();
    }

    myFile.open(REQUEST_DATABASE, std::ios::out);
    if (!myFile.is_open()) {
        cerr << "Fail to reset request.csv file!\n";
    } else {
        myFile << "";
        myFile.close();
    }

    myFile.open(REVIEW_DATABASE, std::ios::out);
    if (!myFile.is_open()) {
        cerr << "Fail to reset review.csv file!\n";
    } else {
        myFile << "";
        myFile.close();
    }

    myFile.open(SKILL_DATABASE, std::ios::out);
    if (!myFile.is_open()) {
        cerr << "Fail to reset skill.csv file!\n";
    } else {
        myFile << "";
        myFile.close();
    }
}


void FileManager::saveMemberDatabase(vector<Member*> members) {
    resetDatabase();
    fstream memberFile;
    memberFile.open(MEMBER_DATABASE, std::ios::out);

    if (!memberFile.is_open()) {
        cerr << "Fail to create/open member.csv file!\n";   
    }

    for (auto member : members) {
        memberFile 
            << member->getMemberId() << "," 
            << member->getUsername() << "," 
            << member->getPassword() << "," 
            << member->getFullname() << "," 
            << member->getCreditPoint() << "," 
            << member->getPhoneNumber() << "," 
            << member->getEmail() << "," 
            << member->getHomeAddress() << "," 
            << member->getAvailableCity() << "," 
            << Converter::boolToString(member->getAvailableStatus());
        for (auto blockedUser : member->getBlockedUsers()) {
            memberFile << "," << blockedUser;
        }
        memberFile << endl;
        saveAvailabilityDatabase(member->getAvailability());
        saveRequestDatabase(member->getRequest());
        saveReviewDatabase(member->getReview());
        saveSkillDatabase(member->getSkill());
    }
    memberFile.close();
}


void FileManager::saveAvailabilityDatabase(vector<Availability*> availabilities) {
    fstream availabilityFile;
    availabilityFile.open(AVAILABILITY_DATABASE, std::ios::out | std::ios::app);

    if (!availabilityFile.is_open()) {
        cerr << "Fail to create/open availability.csv file!\n";   
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


void FileManager::saveRequestDatabase(vector<Request*> requests) {
    fstream requestFile;
    requestFile.open(REQUEST_DATABASE, std::ios::out | std::ios::app);

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


void FileManager::saveReviewDatabase(vector<Review*> reviews) {
    fstream reviewFile;
    reviewFile.open(REVIEW_DATABASE, std::ios::out | std::ios::app);

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


void FileManager::saveSkillDatabase(vector<Skill*> skills) {
    fstream skillFile;
    skillFile.open(SKILL_DATABASE, std::ios::out | std::ios::app);

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


Admin FileManager::loadAdminDatabase() {
    fstream adminFile;
    Admin admin;
    adminFile.open(ADMIN_DATABASE, std::ios::in);
    if (!adminFile.is_open()) {
        cerr << "Fail to create/open admin.csv file!\n";
        return {};

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


vector<Member*> FileManager::loadMemberDatabase() {
    vector<Availability*> allAvailabilities = loadAvailabilityDatabase();
    vector<Request*> allRequests = loadRequestDatabase();
    vector<Review*> allReviews = loadReviewDatabase();
    vector<Skill*> allSkills = loadSkillDatabase();
    vector<Member*> members = {};
    
    fstream memberFile;
    memberFile.open(MEMBER_DATABASE, std::ios::in);
    if (!memberFile.is_open()) {
        cerr << "Fail to create/open member.csv file!\n";
        return {};
    }
    
    while(true) {
        // memberID
        string memberID;
        getline(memberFile, memberID, ',');

        // username
        string username;
        getline(memberFile, username, ',');
        
        // password
        string password;
        getline(memberFile, password, ',');
        
        // fullname
        string fullname;
        getline(memberFile, fullname, ',');
        
        // creditPoint
        string creditPoint;
        getline(memberFile, creditPoint, ',');
        
        // phoneNumber
        string phoneNumber;
        getline(memberFile, phoneNumber, ',');
        
        // email
        string email;
        getline(memberFile, email, ',');
        
        // homeAddress
        string homeAddress;
        getline(memberFile, homeAddress, ',');
        
        // city
        string city;
        getline(memberFile, city, ',');
        
        // availableStatus
        string availableStatus;
        getline(memberFile, availableStatus, ',');
        
        // availability
        vector<Availability*> memberAvailabilities = {};
        for (auto availability : allAvailabilities) { 
            if (availability->getMemberID() == memberID) {
                memberAvailabilities.push_back(availability);
            }
        }
        
        // skills
        vector<Skill*> memberSkills = {};
        for (auto skill : allSkills)  {
            if (skill->getMemberID() == memberID) {
                memberSkills.push_back(skill);
            }
        }
        
        // requests 
        vector<Request*> memberRequests = {};
        for (auto request : allRequests) {
            if (request->getSupporterID() == memberID) {
                memberRequests.push_back(request);
            }
        }
        
        // reviews
        vector<Review*> memberReviews = {};
        for (auto review : allReviews) {
            if (review->getReviewedID() == memberID) {
                memberReviews.push_back(review);
            }
        }

        // blockedUsers
        string blockedUserData;
        getline(memberFile, blockedUserData);
        std::stringstream blockedUsersStream(blockedUserData);
        string user;
        vector<string> blockedUsers;
        while (getline(blockedUsersStream, user, ',')) {
            if (user != "") {
                blockedUsers.push_back(user);
            }
        }
        // Break the while loop if there is no memberID on the line
        if (memberID == "") {
            break;
        }

        // Create new Member
        Member *member = new (std::nothrow) Member(
            username, 
            password, 
            memberID, 
            fullname, 
            Converter::stringToInteger(creditPoint), 
            phoneNumber, 
            email, 
            homeAddress, 
            city == "Ha Noi" ? availableCity::HaNoi : availableCity::SaiGon, 
            availableStatus == "true" ? true : false, 
            memberSkills, 
            memberAvailabilities, 
            blockedUsers, 
            memberRequests, 
            memberReviews
        );
        members.push_back(member);
    }   
    return members;
}


vector<Availability*> FileManager::loadAvailabilityDatabase() {
    vector<Skill*> skills = loadSkillDatabase();
    vector<Availability*> availabilities = {};
    fstream availabilityFile;
    availabilityFile.open(AVAILABILITY_DATABASE, std::ios::in);
    if (!availabilityFile.is_open()) {
        cerr << "Fail to create/open availability.csv file!\n";
        return {};
    }
    while (true) {
        // MemberID
        string memberID;
        if (!getline(availabilityFile, memberID, ',')) break;
        
        // Point per hour
        string pointPerHour;
        if (!getline(availabilityFile, pointPerHour, ',')) break;
        
        // Min host rate
        string minHostRating;
        if (!getline(availabilityFile, minHostRating, ',')) break;
        
        // TimePeriod
        string startDate, startHourStr, startMinuteStr;
        if (!getline(availabilityFile, startDate, ',')) break;
        if (!getline(availabilityFile, startHourStr, ',')) break;
        if (!getline(availabilityFile, startMinuteStr, ',')) break;
        int startHour = Converter::stringToInteger(startHourStr);
        int startMinute = Converter::stringToInteger(startMinuteStr);
        string endDate, endHourStr, endMinuteStr;
        if (!getline(availabilityFile, endDate, ',')) break;
        if (!getline(availabilityFile, endHourStr, ',')) break;
        if (!getline(availabilityFile, endMinuteStr, ',')) break;
        int endHour = Converter::stringToInteger(endHourStr);
        int endMinute = Converter::stringToInteger(endMinuteStr);
        Time startTime(startDate, startHour, startMinute), endTime(endDate, endHour, endMinute);
        TimePeriod *desiredTime = new (std::nothrow) TimePeriod(startTime, endTime);
        
        // Performed skills
        string skillsStr;
        if (!getline(availabilityFile, skillsStr)) break;
        std::stringstream skillsStream(skillsStr);
        string skillName;
        vector<Skill*> performedSkills = {};
        while (getline(skillsStream, skillName, ',')) {
            for (auto skill : skills) {
                if (skill->getMemberID() == memberID && skill->getName() == skillName) {
                    performedSkills.push_back(skill);
                    break;
                }
            }
        }
        
        // Create new Availability
        Availability *availability = new (std::nothrow) Availability(desiredTime, performedSkills, Converter::stringToInteger(pointPerHour), Converter::stringToDouble(minHostRating), memberID);
        availabilities.push_back(availability);
    }
    return availabilities;
}


vector<Request*> FileManager::loadRequestDatabase() {
    fstream requestFile;
    requestFile.open(REQUEST_DATABASE, std::ios::in);

    if (!requestFile.is_open()) {
        cerr << "Fail to create/open request.csv file!\n"; 
        return {};
    }

    vector<Skill*> allSkills = loadSkillDatabase();
    vector<Request*> requests = {};
    string line;
    while (getline(requestFile, line)) {
        std::stringstream ss(line);
        string requestID, supporterID, hostID, startDate, startHourStr, startMinuteStr, endDate, endHourStr, endMinuteStr, statusStr;
        getline(ss, requestID, ',');
        getline(ss, supporterID, ',');
        getline(ss, hostID, ',');
        getline(ss, startDate, ',');
        getline(ss, startHourStr, ',');
        getline(ss, startMinuteStr, ',');
        getline(ss, endDate, ',');
        getline(ss, endHourStr, ',');
        getline(ss, endMinuteStr, ',');
        getline(ss, statusStr, ',');
        
        int startHour = Converter::stringToInteger(startHourStr);
        int startMinute = Converter::stringToInteger(startMinuteStr);
        int endHour = Converter::stringToInteger(endHourStr);
        int endMinute = Converter::stringToInteger(endMinuteStr);

        Time startTime(startDate, startHour, startMinute), endTime(endDate, endHour, endMinute);
        TimePeriod *desiredTime = new (std::nothrow) TimePeriod(startTime, endTime);

        requestStatus status;
        if (statusStr == "Accepted") {
            status = requestStatus::Accepted;
        } else if (statusStr == "Rejected") {
            status = requestStatus::Rejected;
        } else {
            status = requestStatus::Pending;
        }

        vector<Skill*> requestedSkills;
        string skillName;
        while (getline(ss, skillName, ',')) {
            for (auto &skill : allSkills) {
                if (skill->getMemberID() == supporterID && skill->getName() == skillName) {
                    requestedSkills.push_back(skill);
                    break; // No need to check further once the skill is found
                }
            }
        }

        Request *request = new (std::nothrow) Request(requestID, hostID, supporterID, desiredTime, requestedSkills, status);
        requests.push_back(request);
    }
    return requests;
}


vector<Review*> FileManager::loadReviewDatabase() {
    fstream reviewFile;
    reviewFile.open(REVIEW_DATABASE, std::ios::in);

    if (!reviewFile.is_open()) {
        cerr << "Fail to create/open review.csv file!\n"; 
        return {};
    }

    vector<Review*> reviews = {};
    string line;
    while (getline(reviewFile, line)) {
        std::stringstream ss(line);
        string reviewID, reviewedID, reviewerID, typeStr, ratingScoreStr, comment;
        
        getline(ss, reviewID, ',');
        getline(ss, reviewedID, ',');
        getline(ss, reviewerID, ',');
        getline(ss, typeStr, ',');
        getline(ss, ratingScoreStr, ',');
        getline(ss, comment, ',');

        reviewType type = (typeStr == "Supporter") ? reviewType::Supporter : reviewType::Host;
        int ratingScore = Converter::stringToInteger(ratingScoreStr);

        Review *review = new (std::nothrow) Review(reviewID, reviewerID, reviewedID, type, comment, ratingScore);
        reviews.push_back(review);
    }
    return reviews;
}


vector<Skill*> FileManager::loadSkillDatabase() {
    fstream skillFile;
    skillFile.open(SKILL_DATABASE, std::ios::in);

    if (!skillFile.is_open()) {
        cerr << "Fail to create/open skill.csv file!\n"; 
        return {};
    }

    vector<Skill*> skills = {};
    string line;
    while (getline(skillFile, line)) {
        std::istringstream ss(line);
        string name, description, memberID;
        if (getline(ss, name, ',') &&
            getline(ss, description, ',') &&
            getline(ss, memberID, ',')) {

            vector<int> ratingScore;
            for (int i = 0; i < 3; ++i) {
                string ratingStr;
                if (!getline(ss, ratingStr, ',')) break;
                int rating = Converter::stringToInteger(ratingStr);
                ratingScore.push_back(rating);
            }

            Skill *skill = new (std::nothrow) Skill(name, description, memberID, ratingScore);
            skills.push_back(skill);
        }
    }

    return skills;
}
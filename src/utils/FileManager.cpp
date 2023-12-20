#include "./FileManager.h"

#include <iostream>
#include <vector>
#include <fstream>

using std::cout;
using std::string;
using std::vector;
using std::fstream;
using std::cerr;
using std::endl;

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

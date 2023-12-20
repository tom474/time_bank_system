#include <./FileManager.h>

#include <iostream>
#include <vector>
#include <fstream>

using std::fstream;
using std::cerr;
using std::endl;

#define REQUEST_DATABASE "request.csv"
#define REVIEW_DATABASE "review.csv"
#define SKILL_DATABASE "skill.csv"

void saveRequestDatabase(vector<Request*> requests) {
    fstream requestFile;
    requestFile.open(REQUEST_DATABASE, std::ios::out | std::ios::app);

    if (!requestFile.is_open()) {
        cerr << "Fail to create/open request.csv file!\n"; 
        return;
    }

    for (auto req : requests) {
        if (req->getStatus() == true) {
            requestFile << "%s, %s, %s, %d, %d, %s, %d, %d, %s", 
            req->getSupporterID(), 
            req->getHostID(), 
            req->getRequestedTime()->getStartTime().getDate(), 
            req->getRequestedTime()->getStartTime().getHour(), 
            req->getRequestedTime()->getStartTime().getMinute(), 
            req->getRequestedTime()->getEndTime().getDate(), 
            req->getRequestedTime()->getEndTime().getHour(), 
            req->getRequestedTime()->getEndTime().getMinute(), 
            req->getStatus();
            for (auto skill : req->getRequestedSkills()) {
                requestFile << ", %s", skill->getName();
            }
            requestFile << endl;
        }
    }
    requestFile.close();
}

void saveReviewDatabase(vector<Review*> reviews) {
    fstream reviewFile;
    reviewFile.open(REVIEW_DATABASE, std::ios::out | std::ios::app);

    if (!reviewFile.is_open()) {
        cerr << "Fail to create/open review.csv file!\n"; 
        return;
    }

    for (auto review : reviews) {
        reviewFile << "%s, %s, %s, %s, %d, %s",
        review->getReviewID(),
        review->getReviewedID(),
        review->getReviewerID(),
        review->getType(),
        review->getRatingScore(),
        review->getComment();
    }
    reviewFile.close();
}

void saveSkillDatabase(vector<Skill*> skills) {
    fstream skillFile;
    skillFile.open(SKILL_DATABASE, std::ios::out | std::ios::app);

    if (!skillFile.is_open()) {
        cerr << "Fail to create/open review.csv file!\n"; 
        return;
    }

    for (auto skill : skills) {
        skillFile << "%s, %s, %s",
        skill->getName(),
        skill->getDescription(),
        skill->getMemberID();
        for (auto ratingScore : skill->getRatingScore()) {
            skillFile << ", %d", ratingScore;
        }
        skillFile << endl;
    }
    skillFile.close();
}
#include <./FileManager.h>


#include <iostream>
#include <vector>
#include <fstream>


using std::cout;
using std::string;
using std::vector;
using std::fstream;
using std::cerr;
using std::endl;

#define MEMBER_DATABASE "member.csv"
#define AVAILABILITY_DATABASE "availability.csv"
#define REQUEST_DATABASE "request.csv"
#define REVIEW_DATABASE "review.csv"
#define SKILL_DATABASE "skill.csv"

void saveMemberDatabase(vector<Member*> members) {
    fstream memberFile;
    memberFile.open(MEMBER_DATABASE, std::ios::out | std::ios::app);
    if (!memberFile.is_open()) {
        cerr << "Fail to create/open " << MEMBER_DATABASE << " file" << endl;   
    }
    for (auto member : members) {
        memberFile << "%s, %s, %d, %s, %s, %s, %s, %s", 
                    member->getMemberId(), 
                    member->getFullname(), 
                    member->getCreditPoint(), 
                    member->getPhoneNumber(),
                    member->getEmail(), 
                    member->getHomeAddress(),
                    member->getAvailableCityName(member->getAvailableCity()), 
                    member->boolToString(member->getAvailableStatus());
        for (auto blockedUser : member->getBlockedUsers()) {
            memberFile << ", %s", blockedUser->getMemberId();
        }
        saveAvailabilityDatabase(member->getAvailability());
        saveRequestDatabase(member->getRequest());
        saveReviewDatabase(member->getReview());
        saveSkillDatabase(member->getSkill());
        memberFile << endl;
    }
    memberFile.close();
}

void saveAvailabilityDatabase(vector<Availability*> availabilities) {
    fstream availabilityFile;
    availabilityFile.open(AVAILABILITY_DATABASE, std::ios::out | std::ios::app);
    if (!availabilityFile.is_open()) {
        cerr << "Fail to create/open " << AVAILABILITY_DATABASE << " file" << endl;   
    }
    for (auto availability : availabilities) {
        availabilityFile << "%s, %d, %d, %s, %d, %d, %s, %d, %d", 
                            availability->getMemberID(),
                            availability->getPointPerHour(),
                            availability->getMinHostRating(),
                            availability->getAvailableTime()->getStartTime().getDate(),
                            availability->getAvailableTime()->getStartTime().getHour(),
                            availability->getAvailableTime()->getStartTime().getMinute(),
                            availability->getAvailableTime()->getEndTime().getDate(),
                            availability->getAvailableTime()->getEndTime().getHour(),
                            availability->getAvailableTime()->getEndTime().getMinute();
        for (auto skill : availability->getPerformedSkills()) {
            availabilityFile << ", %s" , skill->getName();
        }
        availabilityFile << endl;
    }
    availabilityFile.close();
}

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

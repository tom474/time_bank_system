#include "FileManager.h"

#include <iostream>
#include <vector>
#include <fstream>

#define MEMBER_DATABASE "member.csv"
#define AVAILABILITY_DATABASE "availability.csv"
using std::cout;
using std::string;
using std::vector;
using std::fstream;
using std::cerr;
using std::endl;

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



#include "./IdGenerator.h"


#include <iostream>
#include <vector>

using std::string;
using std::vector;

string IdGenerator::generateMemberId() {
    vector<Member*> allMembers = Menu::allMembers;
    if (allMembers.size() == 0) {
        return "MB0001";
    }
    string maxId = allMembers[0]->getMemberId();
    int maxIdToInt =  Converter::stringToInteger(maxId.substr(2)); 
    for (auto &member : allMembers) {
        int memberId = Converter::stringToInteger(member->getMemberId().substr(2));
        if (maxIdToInt < memberId) {
            maxIdToInt = memberId;
        }
    } 
    int newId = maxIdToInt + 1;
    if (newId >= 1000) {
        return "MB" + Converter::intToString(newId);
    } else if (newId >=100) {
        return "MB0" + Converter::intToString(newId);
    } else if (newId >= 10) {
        return "MB00" + Converter::intToString(newId); 
    } else {
        return "MB000" + Converter::intToString(newId);
    }
}

string IdGenerator::generateRequestId() {
    FileManager::saveMemberDatabase(Menu::allMembers);
    vector<Request*> allRequests = FileManager::loadRequestDatabase();
    if (allRequests.size() == 0) {
        return "RQ0001";
    }
    string maxId = allRequests[0]->getRequestID();
    int maxIdToInt =  Converter::stringToInteger(maxId.substr(2)); 
    for (auto &request : allRequests) {
        int requestId = Converter::stringToInteger(request->getRequestID().substr(2));
        if (maxIdToInt < requestId) {
            maxIdToInt = requestId;
        }
    } 
    int newId = maxIdToInt + 1;
    if (newId >= 1000) {
        return "RQ" + Converter::intToString(newId);
    } else if (newId >=100) {
        return "RQ0" + Converter::intToString(newId);
    } else if (newId >= 10) {
        return "RQ00" + Converter::intToString(newId); 
    } else {
        return "RQ000" + Converter::intToString(newId);
    }
}

string IdGenerator::generateReviewId() {
    FileManager::saveMemberDatabase(Menu::allMembers);
    vector<Review*> allReviews = FileManager::loadReviewDatabase();
    if (allReviews.size() == 0) {
        return "RV0001";
    }
    string maxId = allReviews[0]->getReviewID();
    int maxIdToInt =  Converter::stringToInteger(maxId.substr(2)); 
    for (auto &review : allReviews) {
        int reviewId = Converter::stringToInteger(review->getReviewID().substr(2));
        if (maxIdToInt < reviewId) {
            maxIdToInt = reviewId;
        }
    } 
    int newId = maxIdToInt + 1;
    if (newId >= 1000) {
        return "RV" + Converter::intToString(newId);
    } else if (newId >=100) {
        return "RV0" + Converter::intToString(newId);
    } else if (newId >= 10) {
        return "RV00" + Converter::intToString(newId); 
    } else {
        return "RV000" + Converter::intToString(newId);
    }
}
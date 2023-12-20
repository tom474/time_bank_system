#ifndef _MEMBER_H_
#define _MEMBER_H_

#include "./User.h"
#include "../service/Skill.h"
#include "../service/Availability.h"
#include "../service/Request.h"
#include "../service/Review.h"

#include <iostream>
#include <vector>

using std::string;
using std::vector;

enum availableCity {
    HaNoi,
    SaiGon
};

class User;
class Skill;
class Availability;
class Request;
class Review;

class Member : public User {
    private:
        string memberID;
        string fullname;
        int creditPoint;
        string phoneNumber;
        string email;
        string homeAddress;
        availableCity city;
        bool availableStatus;
        vector<Skill*> skills;
        vector<Availability*> availability;
        vector<string> blockedUsers;
        vector<Request*> requests;
        vector<Review*> reviews;
    public:
        Member(
            string usernameVal, 
            string passwordVal, 
            string memberIDVal, 
            string fullnameVal, 
            int creditPointVal, 
            string phoneNumberVal, 
            string emailVal,
            string homeAddressVal, 
            availableCity cityVal, 
            bool availableStatusVal, 
            vector<Skill*> skillsVal, 
            vector<Availability*> availabilityVal, 
            vector<string> blockedUsersVal, 
            vector<Request*> requestsVal, 
            vector<Review*> reviews
        );

        void setAvailableStatus();
        void login();
        void logout();
        void showInfo();
        void blockUser(User &user);
        void unblockUser(User &user);
        void creditsTopUp(int amount);
        void searchSupporter();
        void bookSupporter();
        void viewRequest();
        void acceptRequest(Request &request);
        void rejectRequest(Request &request);
        void rateSupporter();
        void rateHost();
        void addAvailability(Availability &availability);
        string getMemberId();
        string getFullname();
        int getCreditPoint();
        string getPhoneNumber();
        string getEmail();
        bool getAvailableStatus();
        string boolToString(bool status);
        string getAvailableCity();
        string getHomeAddress();
        vector<Availability*> getAvailability();
        vector<Skill*> getSkill();
        vector<Request*> getRequest();
        vector<Review*> getReview();
        vector<string> getBlockedUsers();
        ~Member();
};

#endif
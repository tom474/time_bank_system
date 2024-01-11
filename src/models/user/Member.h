#ifndef _MEMBER_H_
#define _MEMBER_H_

enum availableCity {
    HaNoi,
    SaiGon
};

#include "./User.h"
#include "../service/Skill.h"
#include "../service/Availability.h"
#include "../service/Request.h"
#include "../service/Review.h"
#include "../../utils/Converter.h"
#include "../../utils/InputValidator.h"
#include "../../views/Menu.h"

#include <iostream>
#include <vector>
#include <iomanip>

using std::string;
using std::vector;

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
        bool isResetPassword;
        vector<Skill*> skills;
        vector<Availability*> availability;
        vector<string> blockedUsers;
        vector<Request*> sendingRequests;
        vector<Request*> receivingRequests;
        vector<Review*> reviews;
    public:
        Member();
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
            bool isResetPasswordVal,
            vector<Skill*> skillsVal, 
            vector<Availability*> availabilityVal, 
            vector<string> blockedUsersVal, 
            vector<Request*> sendingRequestsVal, 
            vector<Request*> receivingRequestsVal, 
            vector<Review*> reviews
        );

        void blockMember(Member &member);
        void unblockMember(Member &member);
        void creditsTopUp(int amount);
        void sendRequest(Request &request);
        void receiveRequest(Request &request);
        void addAvailability();
        void addReview(Review &review);
        void removeAvailability();
        void updateAvailability(Request &request, Availability &availability);
        string getMemberId();
        string getFullname();
        int getCreditPoint();
        void setCreditPoint(int creditPoint);
        string getPhoneNumber();
        string getEmail();
        bool getAvailableStatus();
        bool getIsResetPassword();
        void setIsResetPassword(bool isResetPassword);
        void setAvailableStatus(bool status);
        string getAvailableCity();
        string getHomeAddress();
        double getHostRating();
        double getSupporterRating();
        vector<Availability*> getAvailability();
        vector<Skill*> getSkill();
        vector<Request*> getSendingRequest();
        vector<Request*> getReceivingRequest();
        vector<Review*> getReview();
        vector<string> getBlockedUsers();
        void showInfo();
        ~Member();
};

#endif  // _MEMBER_H_
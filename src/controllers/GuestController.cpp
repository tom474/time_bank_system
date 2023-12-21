#include "./GuestController.h"

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::cin;


void GuestController::signUp() {
        string memberID;
        string fullname;
        string username;
        string password;
        int creditPoint = 20;
        string phoneNumber;
        string email;
        string homeAddress;
        availableCity city;
        bool availableStatus;
        vector<Skill*> skills = {};
        vector<Availability*> availability = {};
        vector<string> blockedUsers = {};
        vector<Request*> requests = {};
        vector<Review*> reviews = {};
        
        username = InputValidator::getString("Enter your username: ");
        password = InputValidator::getString("Enter your password: ");
        fullname = InputValidator::getString("Enter your fullname: ");
        availableStatus = InputValidator::getBool("Are you available? (yes/no): ");
        
};


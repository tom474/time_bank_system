#ifndef _FILE_MANAGER_H_
#define _FILE_MANAGER_H_

#include "../models/user/User.h"
#include "../models/user/Admin.h"
#include "../models/user/Member.h"
#include "../models/service/Availability.h"
#include "../models/service/Request.h"
#include "../models/service/Review.h"
#include "../models/service/Skill.h"
#include "./TimeManager.h"
#include "./Converter.h"

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class FileManager {
    private:
        /**
        * Reset the database
        * 
        * @param none
        * @return void
        */
        static void resetDatabase();
    public:
        /**
        * Save all members to member.csv file
        * 
        * @param vector<Member*>: a vector of members
        * @return void
        */
        static void saveMemberDatabase(vector<Member*> members);


        /**
        * Save all availabilities to availability.csv file
        * 
        * @param vector<Availability*>: a vector of availabilities
        * @return void
        */
        static void saveAvailabilityDatabase(vector<Availability*> availabilities);


        /**
        * Save all requests to request.csv file
        * 
        * @param vector<Request*>: a vector of requests
        * @return void
        */
        static void saveRequestDatabase(vector<Request*> requests);


        /**
        * Save all reviews to reviews.csv file
        * 
        * @param vector<Review*>: a vector of reviews
        * @return void
        */
        static void saveReviewDatabase(vector<Review*> reviews);

        
        /**
        * Save all skills to skill.csv file
        * 
        * @param vector<Skill*>: a vector of skills
        * @return void
        */
        static void saveSkillDatabase(vector<Skill*> skills);


        /**
        * Load admin details from the admin.csv file
        * 
        * @param none
        * @return Admin
        */
        static Admin loadAdminDatabase();


        /**
        * Load member database from the member.csv file
        * 
        * @param none
        * @return vector<Member*>
        */
        static vector<Member*> loadMemberDatabase();


        /**
        * Load availability database from the availability.csv file
        * 
        * @param none
        * @return vector<Availability*>
        */
        static vector<Availability*> loadAvailabilityDatabase();


        /**
        * Load request database from the request.csv file
        * 
        * @param none
        * @return vector<Request*>
        */
        static vector<Request*> loadRequestDatabase();


        /**
        * Load review database from the review.csv file
        * 
        * @param none
        * @return vector<Review*>
        */
        static vector<Review*> loadReviewDatabase();


        /**
        * Load skill database from the skill.csv file
        * 
        * @param none
        * @return vector<Skill*>
        */
        static vector<Skill*> loadSkillDatabase();
};

#endif  // _FILE_MANAGER_H_
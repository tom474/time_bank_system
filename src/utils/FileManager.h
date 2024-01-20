#ifndef _FILE_MANAGER_H_
#define _FILE_MANAGER_H_

#include "../models/user/Admin.h"
#include "../models/user/User.h"
#include "../models/user/Member.h"
#include "../models/service/Availability.h"
#include "../models/service/Request.h"
#include "../models/service/Review.h"
#include "../models/service/Skill.h"
#include "./TimeManager.h"
#include "./Converter.h"

#include <iostream>
#include <vector>
#include <filesystem>

using std::cout;
using std::vector;

class Admin;
class Member;
class FileManager {
    private:
        /**
         * Check if the database files exist. If not, create them
         * 
         * @param none
         * @return void
        */
        static void initializeDatabase();

        /**
         * Reset the database files
         *
         * @param none
         * @return void
         */
        static void resetDatabase();

    public:
        /**
         * Save admin's details to admin.csv file
         *
         * @param Admin: an Admin object
         * @return void
         */
        static void saveAdminDatabase(Admin admin);

        /**
         * Save all members to member.csv file
         *
         * @param vector<Member*>: a vector of all members
         * @return void
         */
        static void saveMemberDatabase(vector<Member *> members);

        /**
         * Save all availabilities to availability.csv file
         *
         * @param vector<Availability*>: a vector of all availabilities
         * @return void
         */
        static void saveAvailabilityDatabase(vector<Availability *> availabilities);

        /**
         * Save all requests to request.csv file
         *
         * @param vector<Request*>: a vector of all requests
         * @return void
         */
        static void saveRequestDatabase(vector<Request *> requests);

        /**
         * Save all reviews to reviews.csv file
         *
         * @param vector<Review*>: a vector of all reviews
         * @return void
         */
        static void saveReviewDatabase(vector<Review *> reviews);

        /**
         * Save all skills to skill.csv file
         *
         * @param vector<Skill*>: a vector of all skills
         * @return void
         */
        static void saveSkillDatabase(vector<Skill *> skills);

        /**
         * Load admin's details from the admin.csv file
         *
         * @param none
         * @return Admin: an Admin object
         */
        static Admin loadAdminDatabase();

        /**
         * Load all members from the member.csv file
         *
         * @param none
         * @return vector<Member*>: a vector of all members in the database
         */
        static vector<Member *> loadMemberDatabase();

        /**
         * Load all availabilities from the availability.csv file
         *
         * @param none
         * @return vector<Availability*>: a vector of all availabilities in the database
         */
        static vector<Availability *> loadAvailabilityDatabase();

        /**
         * Load all requests from the request.csv file
         *
         * @param none
         * @return vector<Request*>: a vector of all requests in the database
         */
        static vector<Request *> loadRequestDatabase();

        /**
         * Load all reviews from the review.csv file
         *
         * @param none
         * @return vector<Review*>: a vector of all reviews in the database
         */
        static vector<Review *> loadReviewDatabase();

        /**
         * Load all skills from the skill.csv file
         *
         * @param none
         * @return vector<Skill*> : a vector of all skills in the database
         */
        static vector<Skill *> loadSkillDatabase();
};
#endif // _FILE_MANAGER_H_
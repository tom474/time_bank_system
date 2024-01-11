#ifndef _TABLE_GENERATOR_H_
#define _TABLE_GENERATOR_H_

#include "../models/user/Member.h"

#include <iostream>
#include <vector>

using std::string;

class TableGenerator {
    public:
        /**
         * Generate a table with a header and a list of members
         * 
         * @param title: title of the table
         * @param members: list of members
         * @return void
         */
        static void generateMemberTable(string title, vector<Member *> members);

        /**
         * Generate a table with a header and a list of availabilities
         * 
         * @param title: title of the table
         * @param availabilities: list of availabilities
         * @return void
        */
        static void generateAvailabilityTable(string title, vector<Availability *> availabilities);

        /**
         * Generate a table with a header and a list of requests
         * 
         * @param title: title of the table
         * @param requests: list of requests
         * @return void
        */
        static void generateRequestTable(string title, vector<Request *> requests);

        /**
         * Generate a table with a header and a list of reviews
         * 
         * @param title: title of the table
         * @param reviews: list of reviews
         * @return void
        */
        static void generateReviewTable(string title, vector<Review *> reviews);

        /**
         * Generate a table with a header and a list of skills
         * 
         * @param title: title of the table
         * @param skills: list of skills
         * @return void
        */
        static void generateSkillTable(string title, vector<Skill *> skills);

        /**
         * Generate a table with a header and a list of host
         * 
         * @param title: title of the table
         * @param members: list of members
         * @return void
        */
        static void generateHostTable(string title, vector<Member *> hosts);

        /**
         * Generate a table with a header and a list of supporters
         * 
         * @param title: title of the table
         * @param members: list of members
         * @return void
        */
        static void generateSupporterTable(string title, vector<Member *> supporters);
};

#endif // _TABLE_GENERATOR_H_
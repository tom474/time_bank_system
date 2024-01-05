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
};

#endif // _TABLE_GENERATOR_H_
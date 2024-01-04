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
};

#endif // _TABLE_GENERATOR_H_
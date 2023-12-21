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
        static void resetDatabase();
    public:
        static void saveMemberDatabase(vector<Member*> members);
        static void saveAvailabilityDatabase(vector<Availability*> availabilities);
        static void saveRequestDatabase(vector<Request*> requests);
        static void saveReviewDatabase(vector<Review*> reviews);
        static void saveSkillDatabase(vector<Skill*> skills);
        static Admin loadAdminDatabase();
        static vector<Member*> loadMemberDatabase();
        static vector<Availability*> loadAvailabilityDatabase();
        static vector<Request*> loadRequestDatabase();
        static vector<Review*> loadReviewDatabase();
        static vector<Skill*> loadSkillDatabase();
};

#endif  // _FILE_MANAGER_H_
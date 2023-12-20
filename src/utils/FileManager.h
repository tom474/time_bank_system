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

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void saveMemberDatabase(vector<Member*> members);
void saveAvailabilityDatabase(vector<Availability*> availabilities);
void saveRequestDatabase(vector<Request*> requests);
void saveReviewDatabase(vector<Review*> reviews);
void saveSkillDatabase(vector<Skill*> skills);
Admin loadAdminDatabase();
vector<Member*> loadMemberDatabase();
vector<Availability*> loadAvailabilityDatabase();
vector<Request*> loadRequestDatabase();
vector<Review*> loadReviewDatabase();
vector<Skill*> loadSkillDatabase();

#endif
#ifndef _TIME_MANAGER_H_
#define _TIME_MANAGER_H_

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

void saveMemberDatabase(vector<Member *>);
void saveAvailabilityDatabase(vector<Availability *>);
void saveRequestDatabase(vector<Request *>);
void saveReviewDatabase(vector<Review *>);
void saveSkillDatabase(vector<Skill *>);
Admin loadAdminDatabase();
vector<Member> loadMemberDatabase();
vector<Availability> loadAvailabilityDatabase();
vector<Request> loadRequestDatabase();
vector<Review> loadReviewDatabase();
vector<Skill> loadSkillDatabase();

#endif
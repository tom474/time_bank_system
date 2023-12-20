#include "./utils/FileManager.h"
#include "./utils/TimeManager.h"
#include "./models/service/Availability.h"
#include "./models/service/Request.h"
#include "./models/service/Review.h"
#include "./models/service/Skill.h"
#include "./models/user/Member.h"

#include <iostream>
#include <vector>

using std::vector;

int main() {
    // resetDatabase();
    // vector<Member*> members = {};

    // vector<Skill*> skills = {};
    // Skill *skill1 = new (std::nothrow) Skill("Programming", "Java OOP", "M01", vector<int> {2, 3, 5});
    // Skill *skill2 = new (std::nothrow) Skill("Design", "Design with Figma", "M01", vector<int> {4, 3, 5});
    // skills.push_back(skill1);
    // skills.push_back(skill2);

    // TimePeriod *timePed1 = new (std::nothrow) TimePeriod(Time("01/01/2023", 9, 30), Time("02/01/2023", 9, 30));
    // TimePeriod *timePed2 = new (std::nothrow) TimePeriod(Time("03/01/2023", 9, 30), Time("04/01/2023", 9, 30));

    // vector<Availability*> availabilities = {};
    // Availability *avail1 = new (std::nothrow) Availability(timePed1, skills, 5, 3.5, "M01");
    // Availability *avail2 = new (std::nothrow) Availability(timePed2, skills, 7, 4.0, "M01");
    // availabilities.push_back(avail1);
    // availabilities.push_back(avail2);

    // vector<Request*> requests = {};
    // Request *req1 = new (std::nothrow) Request("RQ01", "M02", "M01", timePed1, skills, requestStatus::Pending);
    // Request *req2 = new (std::nothrow) Request("RQ02", "M03", "M01", timePed1, skills, requestStatus::Pending);
    // requests.push_back(req1);
    // requests.push_back(req2);

    // vector<Review*> reviews = {};
    // Review *rev1 = new (std::nothrow) Review("RV01", "M02", "M01", reviewType::Supporter, "Very Good" , 5);
    // Review *rev2 = new (std::nothrow) Review("RV02", "M03", "M01", reviewType::Supporter, "Very Bad" , 1);
    // reviews.push_back(rev1);
    // reviews.push_back(rev2);

    // vector<string> blockedUsers = {"M03", "M04"};

    // Member *mem1 = new (std::nothrow) Member("test", "123456", "M01", "Test User", 20, "0123456789", "testuser@gmail.com" ,"RMIT University", availableCity::SaiGon, true, skills, availabilities, blockedUsers, requests, reviews);
    // members.push_back(mem1);

    // vector<Skill*> skills2 = {};
    // Skill *skill3 = new (std::nothrow) Skill("Writing", "Creative Writing", "M02", vector<int> {4, 4, 5});
    // Skill *skill4 = new (std::nothrow) Skill("Marketing", "Digital Marketing", "M02", vector<int> {3, 4, 5});
    // skills2.push_back(skill3);
    // skills2.push_back(skill4);

    // TimePeriod *timePeriod3 = new (std::nothrow) TimePeriod(Time("05/01/2023", 10, 30), Time("06/01/2023", 12, 30));
    // TimePeriod *timePeriod4 = new (std::nothrow) TimePeriod(Time("07/01/2023", 14, 30), Time("08/01/2023", 16, 30));

    // vector<Availability*> availabilities2 = {};
    // Availability *avail3 = new (std::nothrow) Availability(timePeriod3, skills2, 6, 4.5, "M02");
    // Availability *avail4 = new (std::nothrow) Availability(timePeriod4, skills2, 8, 4.2, "M02");
    // availabilities2.push_back(avail3);
    // availabilities2.push_back(avail4);

    // vector<Request*> requests2 = {};
    // Request *req3 = new (std::nothrow) Request("RQ03", "M04", "M02", timePeriod3, skills2, requestStatus::Pending);
    // Request *req4 = new (std::nothrow) Request("RQ04", "M05", "M02", timePeriod3, skills2, requestStatus::Pending);
    // requests2.push_back(req3);
    // requests2.push_back(req4);

    // vector<Review*> reviews2 = {};
    // Review *rev3 = new (std::nothrow) Review("RV03", "M04", "M02", reviewType::Supporter, "Excellent", 5);
    // Review *rev4 = new (std::nothrow) Review("RV04", "M05", "M02", reviewType::Supporter, "Good", 4);
    // reviews2.push_back(rev3);
    // reviews2.push_back(rev4);

    // vector<string> blockedUsers2 = {"M04", "M05"};

    // Member *mem2 = new (std::nothrow) Member("anotherUser", "654321", "M02", "Another User", 25, "9876543210", "anotheruser@gmail.com", "ABC University", availableCity::HaNoi, true, skills2, availabilities2, blockedUsers2, requests2, reviews2);
    // members.push_back(mem2);

    // saveMemberDatabase(members);
    vector<Member*> memberDatabase = loadMemberDatabase();
    vector<Availability*> aval = loadAvailabilityDatabase();
    vector<Request*> req = loadRequestDatabase();
    vector<Review*> res = loadReviewDatabase();
    vector<Skill*> sk = loadSkillDatabase();
    // cout << memberDatabase.size();
    cout << res.size() << std::endl;
    cout << aval.size() << std::endl;
    cout << req.size() << std::endl;;
    cout << sk.size() << std::endl;;
    // for (auto &member : memberDatabase) {
    //     member->showInfo();
    // }

    // memberDatabase[1]->showInfo();
} 
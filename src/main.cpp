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
    vector<Skill*> skills = {};
    Skill *skill1 = new (std::nothrow) Skill("Programming", "Java OOP", "M01", vector<int> {2, 3, 5});
    Skill *skill2 = new (std::nothrow) Skill("Design", "Design with Figma", "M01", vector<int> {4, 3, 5});
    skills.push_back(skill1);
    skills.push_back(skill2);

    TimePeriod *timePed1 = new (std::nothrow) TimePeriod(Time("01/01/2023", 9, 30), Time("02/01/2023", 9, 30));
    TimePeriod *timePed2 = new (std::nothrow) TimePeriod(Time("03/01/2023", 9, 30), Time("04/01/2023", 9, 30));

    vector<Availability*> availabilities = {};
    Availability *avail1 = new (std::nothrow) Availability(timePed1, skills, 5, 3.5, "M01");
    Availability *avail2 = new (std::nothrow) Availability(timePed2, skills, 7, 4.0, "M01");
    availabilities.push_back(avail1);
    availabilities.push_back(avail2);

    vector<Request*> requests = {};
    Request *req1 = new (std::nothrow) Request("RQ01", "M02", "M01", timePed1, skills, requestStatus::Pending);
    Request *req2 = new (std::nothrow) Request("RQ02", "M03", "M01", timePed1, skills, requestStatus::Pending);
    requests.push_back(req1);
    requests.push_back(req2);

    vector<Review*> reviews = {};
    Review *rev1 = new (std::nothrow) Review("RV01", "M02", "M01", reviewType::Supporter, "Very Good" , 5);
    Review *rev2 = new (std::nothrow) Review("RV02", "M03", "M01", reviewType::Supporter, "Very Bad" , 1);
    reviews.push_back(rev1);
    reviews.push_back(rev2);

    vector<Member*> members = {};
    Member *mem1 = new (std::nothrow) Member("test", "123456", "M01", "Test User", 20, "0123456789", "testuser@gmail.com" ,"RMIT University", availableCity::SaiGon, true, skills, availabilities, {}, requests, reviews);
    members.push_back(mem1);

    saveMemberDatabase(members);
}
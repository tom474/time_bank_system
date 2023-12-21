#include "./utils/FileManager.h"
#include "./utils/TimeManager.h"
#include "./models/service/Availability.h"
#include "./models/service/Request.h"
#include "./models/service/Review.h"
#include "./models/service/Skill.h"
#include "./models/user/Member.h"
#include "./utils/FileManager.h"
#include "./controllers/GuestController.h"

#include <iostream>
#include <vector>

using std::vector;

int main() {
    GuestController::signUp();
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

    // vector<Skill*> skills3 = {};
    // Skill *skill5 = new (std::nothrow) Skill("Graphic Design", "Adobe Photoshop", "M03", vector<int> {4, 5, 5});
    // Skill *skill6 = new (std::nothrow) Skill("Content Writing", "SEO Writing", "M03", vector<int> {3, 4, 4});
    // skills3.push_back(skill5);
    // skills3.push_back(skill6);

    // TimePeriod *timePeriod5 = new (std::nothrow) TimePeriod(Time("09/01/2023", 11, 30), Time("10/01/2023", 13, 30));
    // TimePeriod *timePeriod6 = new (std::nothrow) TimePeriod(Time("11/01/2023", 15, 30), Time("12/01/2023", 17, 30));

    // vector<Availability*> availabilities3 = {};
    // Availability *avail5 = new (std::nothrow) Availability(timePeriod5, skills3, 7, 4.0, "M03");
    // Availability *avail6 = new (std::nothrow) Availability(timePeriod6, skills3, 9, 4.5, "M03");
    // availabilities3.push_back(avail5);
    // availabilities3.push_back(avail6);

    // vector<Request*> requests3 = {};
    // Request *req5 = new (std::nothrow) Request("RQ05", "M04", "M03", timePeriod5, skills3, requestStatus::Pending);
    // Request *req6 = new (std::nothrow) Request("RQ06", "M05", "M03", timePeriod5, skills3, requestStatus::Pending);
    // requests3.push_back(req5);
    // requests3.push_back(req6);

    // vector<Review*> reviews3 = {};
    // Review *rev5 = new (std::nothrow) Review("RV05", "M04", "M03", reviewType::Supporter, "Excellent", 5);
    // Review *rev6 = new (std::nothrow) Review("RV06", "M05", "M03", reviewType::Supporter, "Good", 4);
    // reviews3.push_back(rev5);
    // reviews3.push_back(rev6);

    // vector<string> blockedUsers3 = {"M04", "M05"};

    // Member *mem3 = new (std::nothrow) Member("designerUser", "111111", "M03", "Designer User", 27, "1234567890", "designeruser@gmail.com", "XYZ Design School", availableCity::SaiGon, true, skills3, availabilities3, blockedUsers3, requests3, reviews3);
    // members.push_back(mem3);

    // vector<Skill*> skills4 = {};
    // Skill *skill7 = new (std::nothrow) Skill("Data Analysis", "Python Pandas", "M04", vector<int> {4, 4, 5});
    // Skill *skill8 = new (std::nothrow) Skill("Project Management", "Agile Methodology", "M04", vector<int> {3, 5, 5});
    // skills4.push_back(skill7);
    // skills4.push_back(skill8);

    // TimePeriod *timePeriod7 = new (std::nothrow) TimePeriod(Time("13/01/2023", 8, 30), Time("14/01/2023", 10, 30));
    // TimePeriod *timePeriod8 = new (std::nothrow) TimePeriod(Time("15/01/2023", 12, 30), Time("16/01/2023", 14, 30));

    // vector<Availability*> availabilities4 = {};
    // Availability *avail7 = new (std::nothrow) Availability(timePeriod7, skills4, 6, 4.2, "M04");
    // Availability *avail8 = new (std::nothrow) Availability(timePeriod8, skills4, 8, 4.8, "M04");
    // availabilities4.push_back(avail7);
    // availabilities4.push_back(avail8);

    // vector<Request*> requests4 = {};
    // Request *req7 = new (std::nothrow) Request("RQ07", "M05", "M04", timePeriod7, skills4, requestStatus::Pending);
    // Request *req8 = new (std::nothrow) Request("RQ08", "M06", "M04", timePeriod7, skills4, requestStatus::Pending);
    // requests4.push_back(req7);
    // requests4.push_back(req8);

    // vector<Review*> reviews4 = {};
    // Review *rev7 = new (std::nothrow) Review("RV07", "M05", "M04", reviewType::Supporter, "Good", 4);
    // Review *rev8 = new (std::nothrow) Review("RV08", "M06", "M04", reviewType::Supporter, "Excellent", 5);
    // reviews4.push_back(rev7);
    // reviews4.push_back(rev8);

    // vector<string> blockedUsers4 = {"M05", "M06"};

    // Member *mem4 = new (std::nothrow) Member("dataAnalyst", "222222", "M04", "Data Analyst", 30, "0987654321", "dataanalyst@gmail.com", "ABC Data Institute", availableCity::HaNoi, true, skills4, availabilities4, blockedUsers4, requests4, reviews4);
    // members.push_back(mem4);

    // FileManager::saveMemberDatabase(members);
    // vector<Member*> memberDatabase = FileManager::loadMemberDatabase();

 
    // for (auto &member : memberDatabase) {
    //     member->showInfo();
    //     cout << "-------------------------- \n";
    // }
} 

// #include "./views/Menu.h"

// int main() {
//     Menu menu = Menu();
//     // menu.printMenu();
//     return 0;
// }

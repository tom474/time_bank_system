// #include "./views/Menu.h"

// int main() {
//     Menu menu = Menu();
//     // menu.printMenu();
//     return 0;
// }

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
}
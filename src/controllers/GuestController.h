#ifndef _GUEST_CONTROLLER_H_
#define _GUEST_CONTROLLER_H_

#include "../models/service/Skill.h"
#include "../models/service/Availability.h"
#include "../models/service/Request.h"
#include "../models/service/Review.h"
#include "../models/user/Member.h"
#include "../utils/InputValidator.h"
#include "../utils/IdGenerator.h"

#include <iostream>

class GuestController {
    public:
        /**
        * Prompts the guest to sign up to be an member
        * 
        * @param none
        * @return void
        */
        static void signUp();
};

#endif // _GUEST_CONTROLLER_H_

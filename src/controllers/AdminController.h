#ifndef _ADMIN_CONTROLLER_H_
#define _ADMIN_CONTROLLER_H_

#include "../models/user/Admin.h"
#include "../models/service/Skill.h"
#include "../models/service/Availability.h"
#include "../models/service/Request.h"
#include "../models/service/Review.h"
#include "../models/user/Member.h"
#include "../utils/InputValidator.h"
#include "../utils/IdGenerator.h"

class Admin;

class AdminController {
    public:
        /**
         * Prompts the guest to sign up to be an member
         *
         * @param none
         * @return bool
         */
        static Admin login();
};

#endif // _ADMIN_CONTROLLER_H_

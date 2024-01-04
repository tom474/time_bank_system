#ifndef _ADMIN_CONTROLLER_H_
#define _ADMIN_CONTROLLER_H_

#include "../models/user/Admin.h"
#include "../models/service/Skill.h"
#include "../models/service/Availability.h"
#include "../models/service/Request.h"
#include "../models/service/Review.h"
#include "../models/user/Member.h"
#include "../utils/InputValidator.h"

class Admin;

class AdminController {
    public:
        /**
         * The log in function for the admin
         *
         * @param none
         * @return Admin
         */
        static Admin login();
};

#endif // _ADMIN_CONTROLLER_H_

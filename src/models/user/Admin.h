#ifndef _ADMIN_H_
#define _ADMIN_H_

#include "./User.h"
#include "./Member.h"

#include <iostream>

class User;

class Admin : public User {
    public:
        Admin(string usernameVal, string passwordVal);
        void login();
        void resetPassword(Member &member);
};

#endif
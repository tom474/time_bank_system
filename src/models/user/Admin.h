#ifndef _ADMIN_H_
#define _ADMIN_H_

#include "./User.h"
#include "./Member.h"

#include <iostream>

class User;

class Admin : public User {
    public:
        Admin();
        Admin(string usernameVal, string passwordVal);
        string getUsername();
        void setUsername(string usernameVal);
        string getPassword();
        void setPassword(string passwordVal);
        ~Admin();
};

#endif  // _ADMIN_H_
#ifndef _ADMIN_H_
#define _ADMIN_H_

#include "./User.h"
#include "./Member.h"
#include "../../utils/InputValidator.h"
#include "../../utils/FileManager.h"
#include "../../views/Menu.h"

#include <iostream>

using std::string;
using std::cout;

class User;

class Admin : public User {
    public:
        Admin();
        Admin(string usernameVal, string passwordVal);
        string getUsername();
        void setUsername(string usernameVal);
        string getPassword();
        void setPassword(string passwordVal);
        void resetPassword();
        ~Admin();
};

#endif  // _ADMIN_H_
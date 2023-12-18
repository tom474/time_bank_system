#ifndef _USER_H_
#define _USER_H_

#include <iostream>

using std::string;

class User {
    private:
        string username;
        string password;
    public:
        User(string usernameVal, string passwordVal);
        
        string getUsername();
        string getPassword();
        void setPassword(string passwordVal);
        void signup();
        void viewSupporter();
};

#endif
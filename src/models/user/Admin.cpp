#include "./Admin.h"

#include <iostream>

Admin::Admin() {}

Admin::Admin(string usernameVal = "", string passwordVal = "")
: User(usernameVal, passwordVal) {}

string Admin::getUsername() {
    return User::getUsername();
}

void Admin::setUsername(string usernameVal) {
    User::setUsername(usernameVal);
}

string Admin::getPassword() {
    return User::getPassword();
}

void Admin::setPassword(string passwordVal) {
    User::setPassword(passwordVal);
}

Admin::~Admin() {}
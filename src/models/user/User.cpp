#include "./User.h"
#include <iostream>

using std::string;

User::User() {}

User::User(string usernameVal = "", string passwordVal = "")
: username(usernameVal), password(passwordVal) {}

string User::getUsername() {
    return username;
}

string User::getPassword() {
    return password;
}

void User::setPassword(string passwordVal) {
    password = passwordVal;
}

void User::setUsername(string usernameVal) {
    username = usernameVal;
}

User::~User() {}
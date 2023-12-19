#include "./User.h"
#include <iostream>

using std::string;

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

void User::signup() {

}

void User::viewSupporter() {

}
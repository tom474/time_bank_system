#include "./Admin.h"

#include <iostream>

Admin::Admin() {}

Admin::Admin(string usernameVal = "", string passwordVal = "")
: User(usernameVal, passwordVal) {}

void Admin::setPassword(string passwordVal) {
    User::setPassword(passwordVal);
}

void Admin::setUsername(string usernameVal) {
    User::setUsername(usernameVal);
}

void Admin::login() {

}

void Admin::resetPassword(Member &member) {

}
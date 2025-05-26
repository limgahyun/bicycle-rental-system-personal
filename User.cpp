#include "User.h"

using namespace std;

User::User() : isLoggedIn(false) {}

User::User(string id, string password) : userId(id), password(password), userRole(USER), isLoggedIn(false) {}

bool User::findUserById(string searchId) {
    return this->userId == searchId;
}

bool User::checkPassword(string inputPassword) {
    return this->password == inputPassword;
}

void User::setLoggedIn(bool status) {
    this->isLoggedIn = status;
}

bool User::getLoggedIn() const {
    return isLoggedIn;
}

string User::getId() const {
    return userId;
} 
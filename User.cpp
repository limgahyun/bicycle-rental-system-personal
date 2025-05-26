#include "User.h"

User::User() : isLoggedIn(false) {}

User::User(std::string id, std::string password) : id(id), password(password), isLoggedIn(false) {}

bool User::findUserById(std::string searchId) {
    return this->id == searchId;
}

bool User::checkPassword(std::string inputPassword) {
    return this->password == inputPassword;
}

void User::setLoggedIn(bool status) {
    this->isLoggedIn = status;
}

bool User::getLoggedIn() const {
    return isLoggedIn;
}

std::string User::getId() const {
    return id;
} 
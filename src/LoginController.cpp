#include "LoginController.h"

LoginController::LoginController() {}

bool LoginController::login(string id, string password) {
    return UserCollection::getInstance()->login(id, password);
}

User* LoginController::getCurrentUser() const {
    return UserCollection::getInstance()->getCurrentUser();
}
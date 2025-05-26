#ifndef LOGIN_CONTROLLER_H
#define LOGIN_CONTROLLER_H

#include <string>
#include "User.h"

// LoginController control class 선언
class LoginController {
private:
    User* currentUser;

public:
    LoginController();
    bool login(std::string id, std::string password);
    void logout();
    User* getCurrentUser() const;
};

#endif
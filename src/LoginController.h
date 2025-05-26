#ifndef LOGIN_CONTROLLER_H
#define LOGIN_CONTROLLER_H

#include <string>
#include "User.h"

using namespace std;

// LoginController control class 선언
class LoginController {
private:
    User* currentUser;

public:
    LoginController();
    bool login(string id, string password);
    User* getCurrentUser() const;
};

#endif
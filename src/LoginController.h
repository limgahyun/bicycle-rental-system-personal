#ifndef LOGIN_CONTROLLER_H
#define LOGIN_CONTROLLER_H

#include <string>
#include "User.h"

using namespace std;

/*
    class: LoginController
    description: 로그인 기능을 제어하는 control 클래스
*/
class LoginController {
private:
    User* currentUser;
    User adminUser;

public:
    LoginController();
    bool login(string id, string password);
    User* getCurrentUser() const;
};

#endif
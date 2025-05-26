#ifndef LOGOUT_CONTROLLER_H
#define LOGOUT_CONTROLLER_H

#include "User.h"
#include <string>

/*
    class: LogoutController
    description: 로그아웃 기능을 제어하는 control 클래스
*/
class LogoutController {
private:
    User* currentUser;

public:
    string logout();
};

#endif 
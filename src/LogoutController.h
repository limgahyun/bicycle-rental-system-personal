#ifndef LOGOUT_CONTROLLER_H
#define LOGOUT_CONTROLLER_H

#include "UserCollection.h"
#include <string>

/*
    class: LogoutController
    description: 로그아웃 기능을 제어하는 control 클래스
*/
class LogoutController {
public:
    LogoutController();
    string logout();
};

#endif
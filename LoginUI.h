#ifndef LOGIN_UI_H
#define LOGIN_UI_H

#include <string>
#include "LoginController.h"

// LoginUI boundary class 선언
class LoginUI {
private:
    LoginController* loginController;

public:
    LoginUI();
    void requestLogin();
    void start();
};

#endif
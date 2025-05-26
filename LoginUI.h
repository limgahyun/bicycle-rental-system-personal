#ifndef LOGIN_UI_H
#define LOGIN_UI_H

#include <string>
#include <fstream>
#include "LoginController.h"

// LoginUI boundary class 선언
class LoginUI {
private:
    LoginController* loginController;
    std::ofstream& out_fp;

public:
    LoginUI(std::ofstream& out_fp);
    void requestLogin(std::string input);
};

#endif
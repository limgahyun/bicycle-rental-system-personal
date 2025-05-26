#ifndef LOGIN_UI_H
#define LOGIN_UI_H

#include <string>
#include <fstream>
#include "LoginController.h"

using namespace std;

// LoginUI boundary class 선언
class LoginUI {
private:
    LoginController* loginController;
    ofstream& out_fp;

public:
    LoginUI(ofstream& out_fp);
    void requestLogin(string input);
};

#endif
#ifndef LOGIN_UI_H
#define LOGIN_UI_H

#include <string>
#include <fstream>
#include "LoginController.h"

using namespace std;

/*
    class: LoginUI
    description: 로그인 boundary 클래스
*/
class LoginUI {
private:
    LoginController* loginController;
    ofstream& outputFile;

public:
    LoginUI(ofstream& outputFile);
    void requestLogin(string input);
};

#endif
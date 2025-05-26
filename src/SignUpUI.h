#ifndef SIGNUP_UI_H
#define SIGNUP_UI_H

#include <string>
#include <fstream>
#include "SignUpController.h"

using namespace std;

/*
    class: SignUpUI
    description: 회원가입 UI 클래스
*/
class SignUpUI {
private:
    SignUpController* signUpController;
    ofstream& outputFile;

public:
    SignUpUI(ofstream& outputFile);
    void requestSignUp(string input);
};

#endif 
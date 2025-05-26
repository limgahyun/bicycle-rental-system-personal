#ifndef SIGNUP_UI_H
#define SIGNUP_UI_H

#include <string>
#include <fstream>
#include "SignUpController.h"

using namespace std;

class SignUpUI {
private:
    SignUpController* signUpController;
    ofstream& out_fp;

public:
    SignUpUI(ofstream& out_fp);
    void requestSignUp(string input);
};

#endif 
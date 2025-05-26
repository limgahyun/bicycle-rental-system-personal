#ifndef SIGNUP_UI_H
#define SIGNUP_UI_H

#include <string>
#include <fstream>
#include "SignUpController.h"

using namespace std;

class SignUpUI {
private:
    SignUpController* signUpController;
    ofstream& outputFile;

public:
    SignUpUI(ofstream& outputFile);
    void requestSignUp(string input);
};

#endif 
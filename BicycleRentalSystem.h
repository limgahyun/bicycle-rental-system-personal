#ifndef BICYCLE_RENTAL_SYSTEM_H
#define BICYCLE_RENTAL_SYSTEM_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "LoginUI.h"
#include "SignUpUI.h"

using namespace std;

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

class BicycleRentalSystem {
private:
    ifstream in_fp;
    ofstream out_fp;
    LoginUI* loginUI;
    SignUpUI* signUpUI;

    void initializeSystem();
    void cleanupSystem();
    void doTask();

public:
    void run();
};

#endif 
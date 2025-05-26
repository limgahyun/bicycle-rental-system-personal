#ifndef REGISTER_BIKE_UI_H
#define REGISTER_BIKE_UI_H

#include <string>
#include <fstream>
#include "RegisterBikeController.h"

using namespace std;

/*
    class: RegisterBikeUI
    description: 자전거 등록을 위한 boundary 클래스
*/
class RegisterBikeUI {
private:
    RegisterBikeController* registerBikeController;
    ofstream& outputFile;

public:
    RegisterBikeUI(ofstream& outFile);
    void requestRegisterBike(string input);
};

#endif 
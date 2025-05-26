#ifndef LOGOUT_UI_H
#define LOGOUT_UI_H

#include <string>
#include <fstream>
#include "LogoutController.h"

using namespace std;

/*
    class: LogoutUI
    description: 로그아웃 UI를 위한 boundary 클래스
*/
class LogoutUI {
private:
    LogoutController* logoutController;
    ofstream& outputFile;

public:
    LogoutUI(ofstream& outFile);
    void requestLogout();
};

#endif 
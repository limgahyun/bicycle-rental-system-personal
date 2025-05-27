#ifndef EXIT_UI_H
#define EXIT_UI_H

#include <fstream>
#include "ExitController.h"

using namespace std;

/*
    class: ExitUI
    description: 프로그램 종료를 위한 boundary 클래스
*/
class ExitUI {
private:
    ExitController* exitController;
    ofstream& outputFile;

public:
    ExitUI(ofstream& outputFile);
    void requestExit();
};

#endif 
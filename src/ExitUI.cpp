#include "ExitUI.h"

ExitUI::ExitUI(ofstream& outputFile) : outputFile(outputFile) {
    exitController = new ExitController();
}

/*
    함수 이름 : ExitUI::requestExit()
    기능	  : 프로그램 종료 요청을 처리하고 결과를 출력
    전달 인자 : 없음
    반환값    : 없음
*/
void ExitUI::requestExit() {
    exitController->exit();
    outputFile << "6.1. 종료" << endl;
} 
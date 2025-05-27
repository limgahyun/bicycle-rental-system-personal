#include "RegisterBikeUI.h"
#include <sstream>

RegisterBikeUI::RegisterBikeUI(ofstream& outputFile) : outputFile(outputFile) {
    registerBikeController = new RegisterBikeController();
}

/*
    함수 이름 : RegisterBikeUI::requestRegisterBike()
    기능	  : 자전거 등록 요청을 처리하고 결과를 출력
    전달 인자 : 입력 문자열
    반환값    : 없음
*/
void RegisterBikeUI::requestRegisterBike(string input) {
    string bikeId, bikeName;
    istringstream iss(input);
    
    // 자전거 ID 추출
    iss >> bikeId >> bikeName;

    outputFile << "3.1. 자전거 등록" << endl;

    if (registerBikeController->registerBike(bikeId, bikeName)) {
        outputFile << "> " << bikeId << " " << bikeName << endl << endl;
    } else {
        outputFile << "> " << "register failed" << endl << endl;
    }
} 
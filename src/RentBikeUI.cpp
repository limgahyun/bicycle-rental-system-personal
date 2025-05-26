#include "RentBikeUI.h"
#include <iostream>
#include <sstream>

RentBikeUI::RentBikeUI(ofstream& outFile) : outputFile(outFile) {
    rentBikeController = new RentBikeController();
}

/*
    함수 이름 : RentBikeUI::requestRental()
    기능	  : 자전거 대여 요청을 처리하고 결과를 출력
    전달 인자 : 입력 문자열
    반환값    : 없음
*/
void RentBikeUI::requestRental(string input) {
    std::string bikeId, bikeName;
    std::istringstream iss(input);
    
    // id, password 추출하기
    iss >> bikeId >> bikeName;

    outputFile << "4.1. 자전거 대여" << endl;

    if (rentBikeController->rentBike(bikeId)) {
        outputFile << "> " << bikeId << bikeName << endl;
    } else {
        outputFile << "> " << "자전거 대여 실패 " << endl;
    }
} 
#include "RentBikeUI.h"
#include <sstream>

RentBikeUI::RentBikeUI(ofstream& outputFile) : outputFile(outputFile) {
    rentBikeController = new RentBikeController();
}

/*
    함수 이름 : RentBikeUI::requestRental()
    기능	  : 자전거 대여 요청을 처리하고 결과를 출력
    전달 인자 : 입력 문자열
    반환값    : 없음
*/
void RentBikeUI::requestRental(string input) {
    string bikeId;
    istringstream iss(input);
    
    // 자전거 ID 추출
    iss >> bikeId;

    outputFile << "4.1. 자전거 대여" << endl;

    if (rentBikeController->rentBike(bikeId)) {
        Bike* bike = rentBikeController->findBikeById(bikeId);
        outputFile << "> " << bike->getBikeId() << " " << bike->getBikeName() << endl << endl;
    } else {
        outputFile << "> " << "자전거 대여 실패" << endl << endl;
    }
} 
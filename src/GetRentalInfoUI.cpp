#include "GetRentalInfoUI.h"

GetRentalInfoUI::GetRentalInfoUI(ofstream& outputFile) : outputFile(outputFile) {
    getRentalInfoController = new GetRentalInfoController();
}

/*
    함수 이름 : GetRentalInfoUI::requestRentalInfoList()
    기능	  : 대여 자전거 목록 조회 요청을 처리하고 결과를 출력
    전달 인자 : 없음
    반환값    : 없음
*/
void GetRentalInfoUI::requestRentalInfoList() {
    vector<Bike*> rentedBikes = getRentalInfoController->getRentalInfoList();
    
    outputFile << "5.1. 자전거 대여 리스트" << endl;
    
    if (rentedBikes.empty()) {
        outputFile << "> 대여 자전거 정보 조회에 실패하였습니다." << endl << endl;
        return;
    }

    for (const Bike* bike : rentedBikes) {
        outputFile << "> " << bike->getBikeId() << " " << bike->getBikeName() << endl << endl;
    }
} 
#ifndef GET_RENTAL_INFO_UI_H
#define GET_RENTAL_INFO_UI_H

#include <string>
#include <fstream>
#include "GetRentalInfoController.h"

using namespace std;

/*
    class: GetRentalInfoUI
    description: 자전거 대여 정보 조회를 위한 boundary 클래스
*/
class GetRentalInfoUI {
private:
    GetRentalInfoController* getRentalInfoController;
    ofstream& outputFile;

public:
    GetRentalInfoUI(ofstream& outFile);
    void requestRentalInfoList();
};

#endif 
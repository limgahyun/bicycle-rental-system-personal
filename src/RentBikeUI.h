#ifndef RENT_BIKE_UI_H
#define RENT_BIKE_UI_H

#include <string>
#include <fstream>
#include "RentBikeController.h"

using namespace std;

/*
    class: RentBikeUI
    description: 자전거 대여를 위한 boundary 클래스
*/
class RentBikeUI {
private:
    RentBikeController* rentBikeController;
    ofstream& outputFile;

public:
    RentBikeUI(ofstream& outFile);
    void requestRental(string input);
};

#endif 
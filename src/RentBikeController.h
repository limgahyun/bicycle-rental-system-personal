#ifndef RENT_BIKE_CONTROLLER_H
#define RENT_BIKE_CONTROLLER_H

#include <string>
#include <vector>
#include "Bike.h"
#include "UserCollection.h"

using namespace std;

/*
    class: RentBikeController
    description: 자전거 대여를 위한 control 클래스
*/
class RentBikeController {
private:
    static vector<Bike*> bikes;  // 자전거 목록
    bool isRentalAvailable(string bikeId);

public:
    RentBikeController();
    bool rentBike(string bikeId);
    static void addBike(Bike* bike);  // 자전거 추가 (테스트용)
    static Bike* findBikeById(const string& bikeId);
    static const vector<Bike*>& getBikes() { return bikes; }  // 자전거 목록 조회
};

#endif 
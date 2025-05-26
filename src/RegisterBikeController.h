#ifndef REGISTER_BIKE_CONTROLLER_H
#define REGISTER_BIKE_CONTROLLER_H

#include <string>
#include "Bike.h"
#include "UserCollection.h"

using namespace std;

/*
    class: RegisterBikeController
    description: 자전거 등록을 위한 control 클래스
*/
class RegisterBikeController {
public:
    RegisterBikeController();
    bool registerBike(string bikeId, string bikeName);
    bool isDuplicatedId(string bikeId);
    void addNewBike(string bikeId, string bikeName);
};

#endif 
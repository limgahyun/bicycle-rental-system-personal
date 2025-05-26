#ifndef GET_RENTAL_INFO_CONTROLLER_H
#define GET_RENTAL_INFO_CONTROLLER_H

#include <string>
#include <vector>
#include "Bike.h"
#include "UserCollection.h"

using namespace std;

/*
    class: GetRentalInfoController
    description: 자전거 대여 정보 조회를 위한 control 클래스
*/
class GetRentalInfoController {
public:
    GetRentalInfoController();
    vector<Bike*> getRentalInfoList();
    vector<Bike*> findAllRentedBikes();
};

#endif 
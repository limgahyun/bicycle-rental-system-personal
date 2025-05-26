#include "GetRentalInfoController.h"
#include "RentBikeController.h"

GetRentalInfoController::GetRentalInfoController() {}

/*
    함수 이름 : GetRentalInfoController::getRentalInfoList()
    기능	  : 현재 로그인한 사용자의 대여 자전거 목록 조회
    전달 인자 : 없음
    반환값    : 대여중인 자전거 목록
*/
vector<Bike*> GetRentalInfoController::getRentalInfoList() {
    // 로그인한 사용자 확인
    User* currentUser = UserCollection::getInstance()->getCurrentUser();
    if (currentUser == nullptr) {
        return vector<Bike*>();
    }

    // 대여중인 자전거 목록 조회
    return findAllRentedBikes();
}

/*
    함수 이름 : GetRentalInfoController::findAllRentedBikes()
    기능	  : 대여중인 자전거 목록 조회
    전달 인자 : 없음
    반환값    : 대여중인 자전거 목록
*/
vector<Bike*> GetRentalInfoController::findAllRentedBikes() {
    vector<Bike*> rentedBikes;
    const vector<Bike*>& allBikes = RentBikeController::getBikes();
    
    for (Bike* bike : allBikes) {
        if (bike->getIsRented()) {
            rentedBikes.push_back(bike);
        }
    }
    
    return rentedBikes;
} 
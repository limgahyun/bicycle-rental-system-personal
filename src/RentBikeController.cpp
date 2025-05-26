#include "RentBikeController.h"

// 정적 멤버 초기화
vector<Bike*> RentBikeController::bikes;

RentBikeController::RentBikeController() {}

/*
    함수 이름 : RentBikeController::rentBike()
    기능	  : 자전거 대여
    전달 인자 : 자전거 아이디
    반환값    : 자전거 대여 성공 여부
*/
bool RentBikeController::rentBike(string bikeId) {
    // 로그인한 유저 확인    
    User* currentUser = UserCollection::getInstance()->getCurrentUser();
    // 자전거 찾기
    Bike* bike = findBikeById(bikeId);

    // 자전거 대여 가능 여부 확인
    if ((currentUser == nullptr) || (bike == nullptr) || (!isRentalAvailable(bikeId))) {
        return false;
    }
    
    // 자전거 대여
    bike->rent();
    return true;
}

/*
    함수 이름 : RentBikeController::isRentalAvailable()
    기능	  : 자전거 대여 가능 여부 확인
    전달 인자 : 자전거 아이디
    반환값    : 자전거 대여 가능 여부
*/
bool RentBikeController::isRentalAvailable(string bikeId) {
    Bike* bike = findBikeById(bikeId);
    if (bike == nullptr) {
        return false;
    }
    return bike->isRentalAvailable();
}

/*
    함수 이름 : RentBikeController::addBike()
    기능	  : 자전거 추가
    전달 인자 : 자전거 포인터
    반환값    : 없음
*/
void RentBikeController::addBike(Bike* bike) {
    bikes.push_back(bike);
}

/*
    함수 이름 : RentBikeController::findBikeById()
    기능	  : 자전거 찾기
    전달 인자 : 자전거 아이디
    반환값    : 자전거 포인터
*/
Bike* RentBikeController::findBikeById(const string& bikeId) {
    for (Bike* bike : bikes) {
        if (bike->getBikeId() == bikeId) {
            return bike;
        }
    }
    return nullptr;
} 
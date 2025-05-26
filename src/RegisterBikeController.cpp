#include "RegisterBikeController.h"
#include "RentBikeController.h"

RegisterBikeController::RegisterBikeController() {}

/*
    함수 이름 : RegisterBikeController::registerBike()
    기능	  : 자전거 등록
    전달 인자 : 자전거 아이디, 자전거 이름
    반환값    : 등록 성공 여부
*/
bool RegisterBikeController::registerBike(string bikeId, string bikeName) {
    // current user가 admin인지 확인
    User* currentUser = UserCollection::getInstance()->getCurrentUser();
    if (currentUser == nullptr || currentUser->getId() != "admin") {
        return false;
    }

    // 자전거 아이디 중복 확인
    if (isDuplicatedId(bikeId)) {
        return false;
    }

    // 새로운 자전거 등록
    addNewBike(bikeId, bikeName);
    return true;
}

/*
    함수 이름 : RegisterBikeController::isDuplicatedId()
    기능	  : 자전거 아이디 중복 확인
    전달 인자 : 자전거 아이디
    반환값    : 중복 여부
*/
bool RegisterBikeController::isDuplicatedId(string bikeId) {
    return RentBikeController::findBikeById(bikeId) != nullptr;
}

/*
    함수 이름 : RegisterBikeController::addNewBike()
    기능	  : 새로운 자전거 추가
    전달 인자 : 자전거 아이디, 자전거 이름
    반환값    : 없음
*/
void RegisterBikeController::addNewBike(string bikeId, string bikeName) {
    Bike* newBike = new Bike(bikeId, bikeName);
    RentBikeController::addBike(newBike);
} 
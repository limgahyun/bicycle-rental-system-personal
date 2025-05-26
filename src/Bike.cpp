#include "Bike.h"

Bike::Bike(string id) : bikeId(id), isRented(false) {}

/*
    함수 이름 : Bike::isRentalAvailable()
    기능	  : 자전거 대여 가능 여부 확인
    전달 인자 : 없음
    반환값    : 자전거 대여 가능 여부
*/
bool Bike::isRentalAvailable() const {
    return !isRented;
}

/*
    함수 이름 : Bike::rent()
    기능	  : 자전거 대여
    전달 인자 : 없음
    반환값    : 없음
*/
void Bike::rent() {
    isRented = true;
} 
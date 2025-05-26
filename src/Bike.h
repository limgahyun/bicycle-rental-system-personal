#ifndef BIKE_H
#define BIKE_H

#include <string>

using namespace std;

/*
    class: Bike
    description: 자전거 entity 클래스
*/
class Bike {
private:
    string bikeId;
    bool isRented;

public:
    Bike(string id);
    bool isRentalAvailable() const;
    void rent();
    string getBikeId() const { return bikeId; }
    bool getIsRented() const { return isRented; }
};

#endif 
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
    string bikeName;
    bool isRented;

public:
    Bike(string id, string name);
    bool isRentalAvailable() const;
    void rent();
    string getBikeId() const { return bikeId; }
    string getBikeName() const { return bikeName; }
    bool getIsRented() const { return isRented; }
};

#endif 
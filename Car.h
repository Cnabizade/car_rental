#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
protected:
    int seats;
public:
    Car(std::string plate, double rate, int s) : Vehicle(plate, rate), seats(s) {}
};

#endif

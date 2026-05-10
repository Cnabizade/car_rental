#ifndef PETROLCAR_H
#define PETROLCAR_H

#include "Car.h"
#include <string>

class PetrolCar : public Car {
public:
    PetrolCar(std::string plate, double rate, int s)
        : Car(plate, rate, s) {}

    double calculateCost(int days) const override {
        return dailyRate * days;
    }

    std::string getDescription() const override {
        return "Petrol Car [" + licensePlate + "] - " + std::to_string(seats) + " seats";
    }
};

#endif

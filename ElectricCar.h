#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "Car.h"

class ElectricCar : public Car {
public:
    ElectricCar(std::string plate, double rate, int s) : Car(plate, rate, s) {}

    double calculateCost(int days) const override {
        return (dailyRate * days) * 0.85; // 15% discount for EVs
    }

    std::string getDescription() const override {
        return "Electric Car [" + licensePlate + "] - " + std::to_string(seats) + " seats";
    }
};

#endif

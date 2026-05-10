#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
protected:
    std::string licensePlate;
    double dailyRate;
    bool isRented;

public:
    Vehicle(std::string plate, double rate) 
        : licensePlate(plate), dailyRate(rate), isRented(false) {}

    virtual ~Vehicle() = default;

    bool getIsRented() const { return isRented; }
    
    void setRented(bool status) { isRented = status; }

    virtual double calculateCost(int days) const = 0;
    virtual std::string getDescription() const = 0;

    std::string getPlate() const { return licensePlate; }
    double getRate() const { return dailyRate; }
};

#endif

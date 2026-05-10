#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>

class Vehicle {
protected:
    std::string licensePlate;
    double dailyRate;
    bool isRented;

public:
    Vehicle(std::string plate, double rate);
    virtual ~Vehicle() = default;

    virtual double calculateCost(int days) const = 0; // Pure virtual
    virtual std::string getDescription() const = 0;
    
    std::string getPlate() const { return licensePlate; }
    double getRate() const { return dailyRate; }
    bool getStatus() const { return isRented; }
    void setRented(bool status) { isRented = status; }
};
#endif

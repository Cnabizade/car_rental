#ifndef RENTALREGISTRY_H
#define RENTALREGISTRY_H

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include "RentalException.h"

template <typename T>
class RentalRegistry {
private:
    std::vector<std::unique_ptr<T>> inventory; // STL Container

public:
    void add(std::unique_ptr<T> item) { inventory.push_back(std::move(item)); }

    // Algorithm 1: std::sort
    void sortByPrice() {
        std::sort(inventory.begin(), inventory.end(), [](const auto& a, const auto& b) {
            return a->getRate() < b->getRate();
        });
    }

    // Algorithm 2: std::find_if
    void rent(const std::string& plate) {
        auto it = std::find_if(inventory.begin(), inventory.end(), [&](const auto& item) {
            return item->getPlate() == plate;
        });

        if (it == inventory.end()) {
            throw RentalException("Vehicle not found!"); // Exception handling
        }
        std::cout << "Successfully rented: " << (*it)->getDescription() << "\n";
    }

    void display() const {
        for (const auto& item : inventory) {
            std::cout << item->getDescription() << " - $" << item->getRate() << "/day\n";
        }
    }
};

#endif

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
    std::vector<std::unique_ptr<T>> inventory;

public:
    void add(std::unique_ptr<T> item) {
        inventory.push_back(std::move(item));
    }

    void sortByPrice() {
        std::sort(inventory.begin(), inventory.end(), [](const auto& a, const auto& b) {
            return a->getRate() < b->getRate();
        });
    }

    void rent(const std::string& plate, int days) {
    auto it = std::find_if(inventory.begin(), inventory.end(), [&](const auto& item) {
        return item->getPlate() == plate;
    });

    if (it == inventory.end()) {
        throw RentalException("Vehicle not found!");
    }

    if ((*it)->getIsRented()) {
        throw RentalException("Vehicle " + plate + " is already rented!");
    }

    if (days <= 0) {
        throw RentalException("Number of rental days must be greater than zero!");
    }

    double originalCost = (*it)->getRate() * days;
    double totalCost = (*it)->calculateCost(days);
    double discountAmount = originalCost - totalCost;

    (*it)->setRented(true);

    std::cout << "Successfully rented: " << (*it)->getDescription() << "\n";
    std::cout << "Rental days: " << days << "\n";
    std::cout << "Original cost: $" << originalCost << "\n";
    std::cout << "Discount amount: $" << discountAmount << "\n";
    std::cout << "Total cost: $" << totalCost << "\n";
}

    void unrent(const std::string& plate) {
        auto it = std::find_if(inventory.begin(), inventory.end(), [&](const auto& item) {
            return item->getPlate() == plate;
        });

        if (it == inventory.end()) {
            throw RentalException("Vehicle not found!");
        }

        if (!(*it)->getIsRented()) {
            throw RentalException("Vehicle " + plate + " is not currently rented!");
        }

        (*it)->setRented(false);
        std::cout << "Successfully returned: " << (*it)->getDescription() << "\n";
    }

    void display() const {
        for (const auto& item : inventory) {
            std::cout << item->getDescription() << " - $" << item->getRate() << "/day ";
            std::cout << (item->getIsRented() ? "[RENTED]" : "[AVAILABLE]") << "\n";
        }
    }
};

#endif

#include <iostream>
#include <memory>
#include <limits>

#include "Vehicle.h"
#include "Car.h"
#include "ElectricCar.h"
#include "PetrolCar.h"
#include "RentalRegistry.h"
#include "RentalException.h"

int main() {
    RentalRegistry<Vehicle> registry;

    registry.add(std::make_unique<ElectricCar>("TESLA-01", 120.0, 5));
    registry.add(std::make_unique<ElectricCar>("LEAF-99", 45.0, 4));
    registry.add(std::make_unique<PetrolCar>("BMW-22", 80.0, 5));

    int choice = 0;

    while (choice != 5) {
        std::cout << "\n--- Car Rental System ---\n";
        std::cout << "1. View Inventory (Sorted by Price)\n";
        std::cout << "2. Rent a Vehicle\n";
        std::cout << "3. Add a Custom Car\n";
        std::cout << "4. Return a Vehicle\n";
        std::cout << "5. Exit\n";
        std::cout << "Selection: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid selection! Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            registry.sortByPrice();
            registry.display();
        }
        else if (choice == 2) {
            std::string plate;
            std::cout << "Enter Plate to Rent: ";
            std::cin >> plate;

            try {
                registry.rent(plate);
            } catch (const RentalException& e) {
                std::cout << "\n>>> ERROR: " << e.what() << " <<<\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else if (choice == 3) {
            int carType;
            std::string plate;
            double rate;
            int seats;

            std::cout << "\nChoose car type:\n";
            std::cout << "1. Electric Car\n";
            std::cout << "2. Petrol Car\n";
            std::cout << "Selection: ";

            if (!(std::cin >> carType)) {
                std::cout << "Invalid car type! Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            std::cout << "Enter Plate: ";
            std::cin >> plate;

            std::cout << "Enter Daily Rate: ";
            if (!(std::cin >> rate)) {
                std::cout << "Invalid rate! Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            std::cout << "Enter Number of Seats: ";
            if (!(std::cin >> seats)) {
                std::cout << "Invalid number of seats! Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (carType == 1) {
                registry.add(std::make_unique<ElectricCar>(plate, rate, seats));
                std::cout << "Electric car added successfully!\n";
            }
            else if (carType == 2) {
                registry.add(std::make_unique<PetrolCar>(plate, rate, seats));
                std::cout << "Petrol car added successfully!\n";
            }
            else {
                std::cout << "Invalid car type selected. Car was not added.\n";
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (choice == 4) {
            std::string plate;
            std::cout << "Enter Plate to Return: ";
            std::cin >> plate;

            try {
                registry.unrent(plate);
            } catch (const RentalException& e) {
                std::cout << "\n>>> ERROR: " << e.what() << " <<<\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else if (choice != 5) {
            std::cout << "Invalid menu choice. Please try again.\n";
        }
    }

    std::cout << "Exiting system. Goodbye!\n";
    return 0;
}

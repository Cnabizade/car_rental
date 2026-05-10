#include "RentalRegistry.h"
#include "ElectricCar.h"
#include "Vehicle.h"

int main() {
    RentalRegistry<Vehicle> agency;

    agency.add(std::make_unique<ElectricCar>("EV-101", 80.0, 5));
    agency.add(std::make_unique<ElectricCar>("TESLA-X", 150.0, 4));

    std::cout << "Current Inventory:\n";
    agency.sortByPrice();
    agency.display();

    try {
        agency.rent("EV-101");      // Works
        agency.rent("GHOST-99");    // Throws exception
    } catch (const RentalException& e) {
        std::cout << "Caught Error: " << e.what() << "\n";
    }

    return 0;
}

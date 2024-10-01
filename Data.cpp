#include "Data.h"

Car::Car() {
    // Initialize car attributes
}

Car::~Car() {
    // Clean up if necessary
}

std::string Car::getMake() {
    return make; // Return the make of the car
}

void Car::setMake(const std::string& make) {
    this->make = make; // Set the car make
}

void Car::printDetails() {
    // Print car details (make, model, year, price)
}

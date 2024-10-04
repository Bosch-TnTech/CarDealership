#include "Data.h"

Car::Car() {
    // Initialize car attributes
    string make;
    string model;
    int year = 0;
    double price = 0;
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
    cout << "\nMake: " << getMake() << "\nModel: " << getModel() << endl;
    cout << "Year: " << getYear() << "\nPrice: " << getPrice() << endl;
}

std::string Car::getModel() {
    return model;
}

void Car::setModel(const std::string& model){
    this->model = model;
}

int Car::getYear(){
    return year;
}

void Car::setYear(const int& year){
    this->year = year;
}

double Car::getPrice(){
    return price;
}

void Car::setPrice(const double& price){
    this->price = price;
}

#include "Data.h"
#include <iostream>
using namespace std;


Data::Data(const string& make, const std::string& model, int year, double price)
    : make(make), model(model), year(year), price(price) {}

string Data::getMake() const { return make; }
string Data::getModel() const { return model; }
int Data::getYear() const { return year; }
double Data::getPrice() const { return price; }

void Data::displayInfo() const {
    cout << "Make: " << make << ", Model: " << model << ", Year: " << year << ", Price: $" << price << std::endl;
}
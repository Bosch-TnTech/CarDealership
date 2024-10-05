#include "Data.h"
#include <iostream>

using namespace std;

/*
    constructor initializes the car's make, model, year, and price
    using an initalizor list here to DIRECTLY set the member variables
*/
Data::Data(const string& make, const string& model, int year, double price)
    : make(make), model(model), year(year), price(price) {}


//This function returns the make of the car
string Data::getMake() const { return make; }

//returns the model
string Data::getModel() const { return model; }

//return the year the car was made.
int Data::getYear() const { return year; }

// returns the price of the car. a double is included since prices have decimals.
double Data::getPrice() const { return price; }


/*
    This function prints out all the details of the car
    Using cout to display everything. The price is printed with a $ sign.
    Also using endl to move to the next line and flush the output buffer.
*/
void Data::displayInfo() const {
    cout << "Make: " << make << ", Model: " << model << ", Year: " << year << ", Price: $" << price << endl;
}
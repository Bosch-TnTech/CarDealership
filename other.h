#ifndef OTHER_H
#define OTHER_H

#include "Data.h"

using namespace std;

//// The Other class handles utility functions for working with cars
// It can sort cars by price, filter cars by make, and display dealership info
class Other {
public:
    // This function sorts the array of cars by their price in ascending order
    // It takes a pointer to an array of car objects (Data**) and the number of cars (int)
    void sortCarsByPrice(Data** cars, int carCount);
    // This function filters the cars based on their make (e.g., "Ford", "Toyota")
    // It prints the details of the cars that match the given make

    void filterCarsByMake(Data** cars, int carCount, const std::string& make);
    // This function displays the dealership's information (name, location, phone number)
    void displayDealershipInfo() const;
};

#endif

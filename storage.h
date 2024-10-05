#ifndef STORAGE_H
#define STORAGE_H

#include "Data.h"
#include <string>

using namespace std;

class Storage {
private:
    
    Data** cars;  // Pointer to an array of pointers to Data objects (the cars): thank you lab 1!!!
    int carCount;

public:
    // Constructor: Initializes the car inventory (sets cars to nullptr and carCount to 0)
    Storage();
     // Destructor: Frees the dynamically allocated memory for the car array and the cars themselves
    ~Storage();

    // Loads the car data from a file (e.g., cars.txt)
    // The file should contain the number of cars and details about each car
    bool loadCarsFromFile(const std::string& filename);

    // Prints the entire car inventory (just the make, model, and year)
    void printCarInventory() const;

    // Prints detailed information about a specific car (including price)
    // The index refers to the position of the car in the array (starts at 0)
    void getCarInfo(int index) const;

    // Returns the total number of cars in the inventory
    int getCarCount() const;

    // Returns a pointer to the array of car objects (used for sorting or filtering)
    Data** getCarArray() const;
};

#endif

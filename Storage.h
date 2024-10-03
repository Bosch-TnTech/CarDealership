#ifndef STORAGE_H
#define STORAGE_H

#include "Data.h"

class Storage {
private:
    Car** cars;      // Pointer to an array of Car objects
    int carCount;    // Number of cars
    ifstream myfile;
    int numCars;
    string cmake;
    string cmodel;
    int cyear;
    float cprice;

public:
    Storage();       // Constructor
    ~Storage();      // Destructor

    bool loadCarsFromFile(const std::string& filename); // Loads cars from a file
    void printCarInventory();                           // Prints all cars
    void getCarInfo(int carIndex);                      // Displays car details
    Car** getCarArray();                                // Returns array of cars
    int getCarCount();                                  // Returns number of cars
    void printFilteredCars(Car** filteredCars);        // Prints filtered cars
};

#endif // STORAGE_H

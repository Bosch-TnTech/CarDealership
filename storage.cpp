#include "Storage.h"
#include <iostream>
#include <fstream>
using namespace std;

Storage::Storage() {
    // Initialize variables here
    carCount = 0;
    cars = NULL;

}

Storage::~Storage() {
    // Clean up memory here

    for(int i = 0; i < carCount; i++)
    {
        delete cars[i];
    }

    delete [] cars;
}

bool Storage::loadCarsFromFile(const string& filename) {
    // Implementation for loading cars from a file


    myfile.open(filename);

    if(myfile.is_open() )
    {
        while(getline(myfile, line, ' '))
        {
            carCount++;
        }

        carCount = carCount/4;

        Car** cars = new Car*[carCount];

        myfile.clear();
        myfile.seekg(0,myfile.beg);

        for(int i=0; i < carCount; i++)
        {
            getline(myfile, cmake, ',');
            cars[i]->setMake(cmake);

            getline(myfile, cmodel, ',');
            cars[i]->setModel(cmodel);

            getline(myfile, cyear, ',');
            cars[i]->setYear(stoi(cyear));

            getline(myfile, cprice, ',');
            cars[i]->setPrice(stof(cprice));

        }

        myfile.close();

        return true;
    }
    else
    {
        cout << endl << "Problem loading the file." << endl;
        return false;
    }

   
}

void Storage::printCarInventory() {
    // Loop through cars and print details

    for(int i = 0; i < carCount; i++)
    {
        cout << endl;
        cout << "Car " << i+1 << ": ";
        cout << endl;
        cout << "Make - " << cars[i]->getMake() << endl;
        cout << "Model - " << cars[i]->getModel() << endl;
        cout << "Year - " << cars[i]->getYear() << endl;
        cout << "Price - " << cars[i]->getPrice() << endl;
    }

}

void Storage::getCarInfo(int carIndex) {
    // Display specific car information
    cout << endl;
    cout << "Car " << carIndex << ": ";
    cout << endl;
    cout << "Make - " << cars[carIndex]->getMake() << endl;
    cout << "Model - " << cars[carIndex]->getModel() << endl;
    cout << "Year - " << cars[carIndex]->getYear() << endl;
    cout << "Price - " << cars[carIndex]->getPrice() << endl;

}

Car** Storage::getCarArray() {

    return cars; // Return the array of cars
}

int Storage::getCarCount() {

    carCount = sizeof(cars)/sizeof(cars[0]);

    return carCount; // Return the number of cars
}

void Storage::printFilteredCars(Car** filteredCars) {
    // Print the filtered list of cars
    
    int size = sizeof(filteredCars)/sizeof(filteredCars[0]);

    for(int i = 0; i < size; i++)
    {
        cout << endl;
        cout << "Car " << i + 1 << ": ";
        cout << endl;
        cout << "Make - " << filteredCars[i]->getMake() << endl; 
        cout << "Model - " << filteredCars[i]->getModel() << endl;
        cout << "Year - " << filteredCars[i]->getYear() << endl;
        cout << "Price - " << filteredCars[i]->getPrice() << endl; 
    }
}

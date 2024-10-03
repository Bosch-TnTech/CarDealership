#include "Storage.h"
#include <iostream>
#include <fstream>
using namespace std;

Storage::Storage() {
    // Initialize variables here
    ifstream myfile;
    int numCars = 0;
    string cmake;
    string cmodel;
    int cyear = 0;
    float cprice = 0

}

Storage::~Storage() {
    // Clean up memory here

    for(int i = 0; i < numCars; i++)
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
            numCars++;
        }

        numCars = numCars/4;

        Cars** cars = new cars*[numCars];

        myfile.clear();
        myfile.seekg(0,myfile.beg);

        for(int i=0; i < numCars, i++)
        {
            getline(myfile, cmake, ' ');
            cars[i+1]->make =  cmake;

            getline(myfile, cmodel, ' ');
            cars[i+1]->model = cmodel;

            getline(myfile, cyear, ' ');
            cars[i+1]->year = cyear;

            getline(myfile, cprice, ' ');
            cars[i+1]->price = cprice;

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

    for(int i = 0; i < numCars; i++)
    {
        cout << endl;
        cout << "Car " << i+1 << ": ";
        cout << endl;
        cout << "Make - " << cars[i]->make << endl;
        cout << "Model - " << cars[i]->model << endl;
        cout << "Year - " << cars[i]->year << endl;
        cout << "Price - " << cars[i]->price << endl;
    }

}

void Storage::getCarInfo(int carIndex) {
    // Display specific car information
    cout << endl;
    cout << "Car " << carIndex << ": ";
    cout << endl;
    cout << "Make - " << cars[carIndex]->make << endl;
    cout << "Model - " << cars[carIndex]->model << endl;
    cout << "Year - " << cars[carIndex]->year << endl;
    cout << "Price - " << cars[carIndex]->price << endl;

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
        cout << "Make - " << filteredCars[i]->make << endl; 
        cout << "Model - " << filteredCars[i]->model << endl;
        cout << "Year - " << filteredCars[i]->year << endl;
        cout << "Price - " << filteredCars[i]->price << endl; 
    }
}

#include "Storage.h"  
#include "Data.h"   
#include <fstream>    // For file operations
#include <sstream>    // For parsing lines from the file
#include <iostream>
using namespace std;

Storage::Storage() {
    // Initialize variables here
    this->carcount = 0;
    this->cars = nullptr;
}

Storage::~Storage() {
    // Clean up memory here
    if (cars != nullptr)
    {
        for (int = 0; i < carCount; i++)
        {
            delete cars[i]:
        }
        delete[] cars;
    }


bool Storage::loadCarsFromFile(const string& filename) 
{
    ifstream file(filename);
    if(!file)
    {
        cerr << "Unable to open file: " << filename << endl;
        return false;
    }
    string line;
    carCount = 0;
    while (getline(file,line))
    {
        carCount++; //Counts each line
    }
    file.clear();
    file.seekg(0);

    this ->cars = new Car*[carCount];

    int index = 0;
    while (getline(file, line))
    {
        stringstream ss(line);
        string make, model;
        int year;
        double price;
        getline (ss, make, ',');
        getline(ss, model. ','):
        ss >> year;
        ss.ignore();
        ss >> price;

        car[index++] = new Car(make, model, year, price);
    }

    file.close();
    return true;
}

void Storage::printCarInventory() 
{
    // Loop through cars and print details
    if (carCount == 0)
    {
        cout << "No cars available in the Inventory!" <<endl;
    }

    for(int i = 0; i < carCount; i++)
    {
        printCarDetails(cars[i], i);
    }

}

void Storage::getCarInfo(int carIndex) {
    // Display specific car information
    if (carIndex < 1 || carIndex > carCount)
    {
        cout << "Invalid car number!" << endl;
        return;
    }

    printCarDetails(cars[carIndex - 1], carIndex -1);
}

Car** Storage::getCarArray()
{
   return cars; // just returning a pointer to the car array
}

int Storage::getCarCount() 
{
    return carCount; // Return the number of cars
}

void Storage::printFilteredCars(Car** filteredCars, int filteredCount) 
{
    // Print the filtered list of cars
    if (filteredCount == 0)
    {
        cout << "No Cars match the filter criteria" << endl;
        return;
    }


    for(int i = 0; i < filteredCount; i++)
    {
        printCarDetails(filteredCars[i], i);
    }
}


void Storage:: printCarDetails(Car* car, int index)
{
        cout << endl;
        cout << "Car " << i+1 << ": ";
        cout << endl;
        cout << "Make - " << car->getMake() << endl;
        cout << "Model - " << car->getModel() << endl;
        cout << "Year - " << car->getYear() << endl;
        cout << "Price - $" << car->getPrice() << endl;
    
}
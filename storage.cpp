#include "Storage.h"
#include <fstream> 
#include <iostream>
#include <iomanip>  //  Needed for formatting output with setw and setprecision : somehow managed to remember this from 1300

using namespace std;

// Constructor initializes the car storage with no cars (nullptr) and carCount set to 0
Storage::Storage() : cars(nullptr), carCount(0) {}

// Destructor to clean up dynamically allocated memory (the cars array)
// Loops through the array of car pointers and deletes each car, then deletes the array itself
Storage::~Storage() {
    if (cars != nullptr) {
        for (int i = 0; i < carCount; i++) {
            delete cars[i];
        }
        delete[] cars;
    }
}

// Function to load car data from a file (cars.txt)
// It reads the number of cars and each car's make, model, year, and price
bool Storage::loadCarsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file." << endl; // Print error if file can't be opened
        return false;
    }

    file >> carCount; // Read the number of cars from the first line
    cars = new Data*[carCount]; // Dynamically allocate an array of car pointers


    string make, model;
    int year;
    double price;
    // Loop through the file and create a new Data object for each car
    for (int i = 0; i < carCount; ++i) {
        file >> make >> model >> year >> price; // Read car details
        cars[i] = new Data(make, model, year, price);  // // Create a new car and store it in the array
    }

    file.close();
    return true;
}

// Function to print the entire car inventory
// It prints the make, model, and year of each car in a list format
void Storage::printCarInventory() const {
    if (carCount == 0) {
        cout << "No cars available in the Inventory!" << endl;
        return;
    }

    cout << "\n***** Car Inventory *****\n";
    for (int i = 0; i < carCount; i++) {
        cout << i + 1 << ". " << cars[i]->getMake() << " " << cars[i]->getModel() << " (" << cars[i]->getYear() << ")" << endl;
    }
    cout << "*************************\n";
}
// Function to print detailed information about a specific car
// The user provides an index (car number) and this function prints all details, including price
void Storage::getCarInfo(int index) const {
    if (index < 0 || index >= carCount) {
        cout << "Invalid car index!" << endl;
        return;
    }

    Data* car = cars[index];

    // Print the details of the selected car in a cleaner format with '*' borders
    cout << "\n********** Car Details **********" << endl;
    cout << left << setw(10) << "Make:" << car->getMake() << endl;
    cout << left << setw(10) << "Model:" << car->getModel() << endl;
    cout << left << setw(10) << "Year:" << car->getYear() << endl;
    cout << left << setw(10) << "Price:" << "$" << fixed << setprecision(2) << car->getPrice() << endl;
    cout << "*********************************\n" << endl;
}
// Returns the total number of cars in the inventory
int Storage::getCarCount() const { return carCount; }

// Returns a pointer to the array of cars (used for sorting or filtering)
Data** Storage::getCarArray() const { return cars; }

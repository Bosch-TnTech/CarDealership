#include "Storage.h"
#include <fstream>
#include <iostream>
#include <iomanip>  // Include for setw, setprecision

using namespace std;

Storage::Storage() : cars(nullptr), carCount(0) {}

Storage::~Storage() {
    if (cars != nullptr) {
        for (int i = 0; i < carCount; i++) {
            delete cars[i];
        }
        delete[] cars;
    }
}

bool Storage::loadCarsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file." << endl;
        return false;
    }

    file >> carCount;
    cars = new Data*[carCount];

    string make, model;
    int year;
    double price;

    for (int i = 0; i < carCount; ++i) {
        file >> make >> model >> year >> price;
        cars[i] = new Data(make, model, year, price);
    }

    file.close();
    return true;
}

void Storage::printCarInventory() const {
    if (carCount == 0) {
        cout << "No cars available in the Inventory!" << endl;
        return;
    }

    cout << "\n****** Car Inventory *****\n";
    for (int i = 0; i < carCount; i++) {
        cout << i + 1 << ". " << cars[i]->getMake() << " " << cars[i]->getModel() << " (" << cars[i]->getYear() << ")" << endl;
    }
    cout << "**************************\n";
}

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
    cout << "\n*********************************" << endl;
}

int Storage::getCarCount() const { return carCount; }

Data** Storage::getCarArray() const { return cars; }

#include <iostream>
#include <string>
#include "Storage.h"
#include "Data.h"
#include "Other.h"

using namespace std;

// Function prototypes
void displayMenu();
void handleUserInput(Storage& storage, Other& other);

int main() {
    // Instantiate the storage and other classes
    Storage carStorage;
    Other carUtils;

    // Load cars from file (assuming Storage class has a function for this)
    if (!carStorage.loadCarsFromFile("cars.txt")) {
        cout << "Error loading car data from file." << endl;
        return 1;  // Exit if file loading fails
    }

    cout << "Welcome to the Car Dealership Program!" << endl;

    // Main program loop
    bool running = true;
    while (running) {
        displayMenu();
        handleUserInput(carStorage, carUtils);
        char continueProgram;
        cout << "Would you like to continue? (y/n): ";
        cin >> continueProgram;
        if (continueProgram == 'n' || continueProgram == 'N') {
            running = false;
        }
    }

    cout << "Thank you for using the Car Dealership Program!" << endl;
    return 0;
}

// Function to display menu options to the user
void displayMenu() {
    cout << "\nMenu Options:" << endl;
    cout << "1. View all cars" << endl;
    cout << "2. View specific car details" << endl;
    cout << "3. Sort cars by price" << endl;
    cout << "4. Filter cars by make" << endl;
    cout << "5. Filter cars by year" << endl;
    cout << "6. Dealership information" << endl;
    cout << "7. Exit" << endl;
    cout << "Please choose an option (1-7): ";
}

// Function to handle user input and process menu actions
void handleUserInput(Storage& storage, Other& other) {
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            // Display all cars
            storage.printCarInventory();
            break;
        }
        case 2: {
            // View specific car details
            int carIndex;
            cout << "Enter the car number you want details for: ";
            cin >> carIndex;
            storage.getCarInfo(carIndex);  // Assuming storage class handles this
            break;
        }
        case 3: {
            // Sort cars by price
            other.sortCarsByPrice(storage.getCarArray(), storage.getCarCount());
            cout << "Cars sorted by price:" << endl;
            storage.printCarInventory();
            break;
        }
        case 4: {
            // Filter cars by make
            string make;
            cout << "Enter the car make: ";
            cin >> make;
            Car** filteredCars = other.filterCarsByMake(storage.getCarArray(), storage.getCarCount(), make);
            cout << "Cars filtered by make:" << endl;
            storage.printFilteredCars(filteredCars);  // Assuming a function for printing filtered cars
            break;
        }
        case 5: {
            // Filter cars by year
            int minYear, maxYear;
            cout << "Enter the minimum year: ";
            cin >> minYear;
            cout << "Enter the maximum year: ";
            cin >> maxYear;
            Car** filteredCars = other.filterCarsByYear(storage.getCarArray(), storage.getCarCount(), minYear, maxYear);
            cout << "Cars filtered by year range:" << endl;
            storage.printFilteredCars(filteredCars);  // Assuming a function for printing filtered cars
            break;
        }
        case 6: {
            // Display dealership information
            other.getDealershipInfo();
            break;
        }
        case 7: {
            // Exit the program
            cout << "Exiting the program..." << endl;
            exit(0);
        }
        default: {
            cout << "Invalid option, please choose again." << endl;
        }
    }
}
#include <iostream>
#include <string>
#include "Storage.h"
#include "Other.h"

using namespace std;

void displayMenu();
void handleUserInput(Storage& storage, Other& other);

int main() {
    Storage carStorage;
    Other carUtils;

    if (!carStorage.loadCarsFromFile("cars.txt")) {
        cout << "Error loading car data from file." << endl;
        return 1;
    }

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

void displayMenu() {
    cout << "\n********** Menu *******************\n";
    cout << "1. View all cars (Make, Model, Year)" << endl;
    cout << "2. View specific car details (Price)" << endl;
    cout << "3. Sort cars by price" << endl;
    cout << "4. Filter cars by make" << endl;
    cout << "5. View Dealership Information" << endl;  // Added dealership info
    cout << "6. Exit" << endl;
    cout << "*************************************\n";
    cout << "Please choose an option: ";
}

void handleUserInput(Storage& storage, Other& other) {
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            storage.printCarInventory();  // Only prints make, model, and year
            break;
        case 2: {
            int carIndex;
            cout << "Enter the car number for more details: ";
            cin >> carIndex;
            storage.getCarInfo(carIndex - 1);  // Display full car details (with price)
            break;
        }
        case 3:
            other.sortCarsByPrice(storage.getCarArray(), storage.getCarCount());
            storage.printCarInventory();  // Display sorted cars (make, model, year)
            break;
        case 4: {
            string make;
            cout << "Enter the car make to filter by: ";
            cin >> make;
            other.filterCarsByMake(storage.getCarArray(), storage.getCarCount(), make);
            break;
        }
        case 5:
            other.displayDealershipInfo();  // Show dealership information
            break;
        case 6:
            cout << "Exiting the program..." << endl;
            exit(0);
        default:
            cout << "Invalid option, please try again." << endl;
    }
}
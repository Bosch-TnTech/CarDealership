#include <iostream>
#include <string>
#include "Storage.h"
#include "Other.h"

using namespace std;

// Function to display the menu options to the user
void displayMenu();

// Function to handle user input based on the menu choice
void handleUserInput(Storage& storage, Other& other);


int main() {
    // Create instances of Storage and Other classes
    Storage carStorage;
    Other carUtils;

    // Load car data from the cars.txt file
    // If the file can't be opened, print an error message and exit
    if (!carStorage.loadCarsFromFile("cars.txt")) {
        cout << "Error loading car data from file." << endl;
        return 1;
    }

    bool running = true; // This flag controls the main program loop
    while (running) {
        
        // display the wonderful menu to user
        displayMenu(); 
        
        // Get user input and perform actions
        handleUserInput(carStorage, carUtils);

        //more user interaction if they want to just are sick and tired of our wonderful program :(
        char continueProgram;
        cout << "Would you like to continue? (y/n): ";
        cin >> continueProgram;

        // if n is selected, We're bummed because it stops the loop and user exits program
        if (continueProgram == 'n' || continueProgram == 'N') {
            running = false;
        }
    }
    // supposed to send a goodbye message when the program ends but we can't seem to get it right lol
    cout << "Thank you for using the Car Dealership Program!" << endl;
    return 0;
}

// This function prints out the menu options for the user
void displayMenu() {
    cout << "\n********** Menu *********************\n";
    cout << "1. View all cars (Make, Model, Year)" << endl;
    cout << "2. View specific car details (Price)" << endl;
    cout << "3. Sort cars by price" << endl;
    cout << "4. Filter cars by make" << endl;
    cout << "5. View Dealership Information" << endl;  // Added dealership info
    cout << "6. Exit" << endl;
    cout << "*************************************\n";
    cout << "Please choose an option: ";
}

// This function handles the user's choice from the menu
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
            string make;  //filter cars by make
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
            // if user inputs something program no likey then error message is displayed
            cout << "Invalid option, please try again." << endl;
    }
}
#include "Other.h"
#include <algorithm> //needed for sort
#include <iostream>

using namespace std;

// This function sorts the cars by price using the C++ std::sort algorithm.
// It takes a pointer to an array of car objects (Data**) and the number of cars.
// The LAMBDA FUNCTION here compares the prices of two cars.
    //Wished I learned this sooner ^^ Simplifes so much "noise"

void Other::sortCarsByPrice(Data** cars, int carCount) {
    sort(cars, cars + carCount, [](Data* a, Data* b) {
        return a->getPrice() < b->getPrice(); // Sorting in ascending order based on price
    });
    cout << "Cars sorted by price!" << endl; 
}

// This function filters the cars by their make (e.g., "Toyota").
// It checks if each car's make matches the user's input and prints matching cars.
// If no cars match the make, it prints a message saying no cars were found.
    // is this too much comments?
void Other::filterCarsByMake(Data** cars, int carCount, const string& make) {
    bool found = false;
    for (int i = 0; i < carCount; i++) {
        if (cars[i]->getMake() == make) {
            cars[i]->displayInfo();  // Full info of matching cars
            found = true; // Set the flag to true if at least one car is found
        }
    }
    if (!found) {
         // If no cars matched the make, inform the user
        cout << "No cars found for make: " << make << endl;
    }
}


void Other::displayDealershipInfo() const {
	// Print dealership details

	cout << "****************************************************\n";
	cout << "*	Crazy Cars Dealership                           *\n";
	cout << "*	Located in Cookeveille TN right of Dixie Drive  *\n";
	cout << "*	Phone Number: 649 563 6483                      *\n";
	cout << "****************************************************\n\n";

}

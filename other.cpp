#include "Other.h"
#include <algorithm>
#include <iostream>

using namespace std;

void Other::sortCarsByPrice(Data** cars, int carCount) {
    sort(cars, cars + carCount, [](Data* a, Data* b) {
        return a->getPrice() < b->getPrice();
    });
    cout << "Cars sorted by price!" << endl;
}

void Other::filterCarsByMake(Data** cars, int carCount, const string& make) {
    bool found = false;
    for (int i = 0; i < carCount; i++) {
        if (cars[i]->getMake() == make) {
            cars[i]->displayInfo();  // Full info of matching cars
            found = true;
        }
    }
    if (!found) {
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

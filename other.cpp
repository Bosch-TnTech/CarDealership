#include "Other.h"
#include <iostream>

using namespace std;

void Other::sortCarsByPrice(Car **cars, int carCount)
{

	sort(cars, cars + carCount, [](Car *a, Car *b){
			return a->getPrice() < b->getPrice(); 
	});
}

Car **Other::filterCarsByMake(Car **cars, int carCount, const std::string &make)
{
	// Implement filtering logic here

	Car **filteredCars = new Car *[carCount];

	int filteredCount = 0;

	for (int i = 0; i < carCount; ++i)
	{
		if (cars[i]->getMake() == make)
		{
			filteredCars[filteredCount++] = cars[i];
		}
	}

	return filteredCars; // Change to actual filtered array
}

Car **Other::filterCarsByYear(Car **cars, int carCount, int minYear, int maxYear)
{
	// Implement filtering logic here

	Car **filteredCars = new Car *[carCount];

	int filteredCount = 0;

	for (int i = 0; i < carCount; i++)
	{
		if (cars[i]->getYear() >= minYear && cars[i]->getYear() <= maxYear)
		{
			filteredCars[filteredCount++] = cars[i];
		}
	}

	return filteredCars; // Change to actual filtered array
}

void Other::getDealershipInfo()
{
	// Print dealership details

	cout << "****************************************************\n";
	cout << "*	Crazy Cars Dealership                           *\n";
	cout << "*	Located in Cookeveille TN right of Dixie Drive  *\n";
	cout << "*	Phone Number: 649 563 6483                      *\n";
	cout << "****************************************************\n\n";

}
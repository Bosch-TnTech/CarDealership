#include "Other.h"
#include <iostream>

void Other::sortCarsByPrice(Car** cars, int carCount) 
{
    Car key;
	int j;

	
	for (int i = 1; i < carCount; i++)
	{
		key = *cars[i];
		j = i - 1;
		while (j >= 0 && cars[j]->getPrice() > key.getPrice())
		{
			cars[j + 1] = cars[j];
			j = j - 1;
		}
		*cars[j + 1] = key;
	}
}

Car** Other::filterCarsByMake(Car** cars, int carCount, const std::string& make) {
    // Implement filtering logic here
    return nullptr; // Change to actual filtered array
}

Car** Other::filterCarsByYear(Car** cars, int carCount, int minYear, int maxYear) 
{
    // Implement filtering logic here

	Car** filteredCars = new Car *[carCount];

	int filteredCount = 0;

	for (int i = 0; i < carCount; i++)
	{
		if(cars[i]->getYear() >= minYear && cars[i]->getYear() <= maxYear)
		{
			filteredCars[filteredCount++] = cars[i];
		}
	}
    
    return filteredCars; // Change to actual filtered array
}

int partSelect(Car **cars, int carCount, int minYear, int maxYear)
{
	Car** filteredCars = new Car*[carCount];

	int filteredCount = 0;


	

}

void Other::getDealershipInfo() {
    // Print dealership details
}

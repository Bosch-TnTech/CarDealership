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

    int pivotPoint;

    pivotPoint = partSelect(cars, minYear, maxYear);
    filterCarsByYear(cars, minYear, pivotPoint);
    filterCarsByYear(cars, pivotPoint + 1, maxYear);

    return nullptr; // Change to actual filtered array
}

int partSelect(Car **cars, int left, int right)
{
	int middle;
	bool finished = false;
	Car * temp;
	string pivot;

	// pivot starting in middle
	middle = left + (right - left) / 2;
	pivot = cars[middle]->getYear();
	int x = left;
	int y = right;
	while (!finished)
	{
		while (cars[x]->getYear() < pivot)
			++x;
		while (pivot < cars[y]->getYear())
			--y;
		if (x >= y)
			finished = true;
		else
		{
			temp = cars[x];
			cars[x] = cars[y];
			cars[y] = temp;
			++x;
			--y;
		}
	}
	return y;

}

void Other::getDealershipInfo() {
    // Print dealership details
}

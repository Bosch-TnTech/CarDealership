#ifndef OTHER_H
#define OTHER_H

#include "Data.h"

class Other {
public:
    void sortCarsByPrice(Car** cars, int carCount); // Sort cars by price
    Car** filterCarsByMake(Car** cars, int carCount, const std::string& make); // Filter cars by make
    Car** filterCarsByYear(Car** cars, int carCount, int minYear, int maxYear); // Filter cars by year
    void getDealershipInfo(); // Print dealership information
};



#endif // OTHER_H


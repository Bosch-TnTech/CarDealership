#ifndef OTHER_H
#define OTHER_H

#include "Data.h"

using namespace std;

class Other {
public:
    void sortCarsByPrice(Data** cars, int carCount);
    void filterCarsByMake(Data** cars, int carCount, const std::string& make);

    void displayDealershipInfo() const;
};

#endif

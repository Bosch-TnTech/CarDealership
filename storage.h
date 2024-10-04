#ifndef STORAGE_H
#define STORAGE_H

#include "Data.h"
#include <string>

using namespace std;

class Storage {
private:
    Data** cars;
    int carCount;

public:
    Storage();
    ~Storage();

    bool loadCarsFromFile(const std::string& filename);
    void printCarInventory() const;
    void getCarInfo(int index) const;

    int getCarCount() const;
    Data** getCarArray() const;
};

#endif

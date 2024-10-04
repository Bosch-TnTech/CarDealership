#ifndef DATA_H
#define DATA_H

#include <string>

using namespace std;

class Data {
private:
    std::string make;
    std::string model;
    int year;
    double price;

public:
    Data(const std::string& make, const std::string& model, int year, double price);

    // Getters
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    double getPrice() const;

    // Display function
    void displayInfo() const;
};

#endif
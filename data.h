#ifndef DATA_H
#define DATA_H

#include <string>

using namespace std;

/* 
    This is the Data class, which will represent a car.
    It stores details like the make, model, year, and price of a car.
*/ 
class Data {
private:
    string make;
    string model;
    int year;
    double price;

public:
    //Constructor for the Data class
    Data(const string& make, const string& model, int year, double price);

    // Getters to access private date members and return info of car
    string getMake() const;
    string getModel() const;
    int getYear() const;
    double getPrice() const;

    // prints car details in a formatted way
    void displayInfo() const;
};

#endif
#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string make;
    string model;
    int year;
    double price;

public:
    Car();    // Constructor
    ~Car();   // Destructor

    // Getters and Setters
    string getMake();
    void setMake(const string& make);
    
    void printDetails(); // Method to print car details
};

#endif // DATA_H

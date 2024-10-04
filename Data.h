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

    string getModel();

    int getYear();

    double getPrice();

    void setMake(const string& make);

    void setModel(const string& model);

    void setPrice(const double& price);

    void setYear(const int& year);
    
    void printDetails(); // Method to print car details
};

#endif // DATA_H

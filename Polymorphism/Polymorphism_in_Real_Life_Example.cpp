/*Design a program to model a vehicle system:

Create a base class Vehicle with a pure virtual function fuelEfficiency().
Derive classes Car and Truck with specific implementations for fuelEfficiency().
In the main() function, create an array of pointers to Vehicle objects and call 
fuelEfficiency() for each.
For example:

Car calculates efficiency as miles / gallons.
Truck considers load weight in the calculation.
*/

#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Vehicle {
public:
    virtual void fuelEfficiency() = 0; // Pure virtual function
    virtual ~Vehicle() {}             // Virtual destructor
};

// Derived Class: Car
class Car : public Vehicle {
    float miles;
    float gallons;

public:
    Car(float m, float g) : miles(m), gallons(g) {}

    void fuelEfficiency() override {
        float efficiency = miles / gallons;
        cout << "Car Fuel Efficiency: " << efficiency << " miles per gallon." << endl;
    }
};

// Derived Class: Truck
class Truck : public Vehicle {
    float miles;
    float gallons;
    float loadWeight; // Weight in tons

public:
    Truck(float m, float g, float load) : miles(m), gallons(g), loadWeight(load) {}

    void fuelEfficiency() override {
        // Assume heavier loads reduce fuel efficiency by 10% per ton
        float baseEfficiency = miles / gallons;
        float efficiency = baseEfficiency - (baseEfficiency * 0.1 * loadWeight);
        cout << "Truck Fuel Efficiency: " << efficiency << " miles per gallon (with load: " 
             << loadWeight << " tons)." << endl;
    }
};

int main() {
    // Array of Vehicle pointers
    Vehicle* vehicles[2];

    // Dynamically allocate objects for Car and Truck
    vehicles[0] = new Car(300, 10);               // 300 miles, 10 gallons
    vehicles[1] = new Truck(500, 25, 2);          // 500 miles, 25 gallons, 2 tons load

    // Display fuel efficiency using polymorphism
    for (int i = 0; i < 2; i++) {
        vehicles[i]->fuelEfficiency();
    }

    // Cleanup
    for (int i = 0; i < 2; i++) {
        delete vehicles[i];
    }

    return 0;
}

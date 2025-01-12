/*Write a C++ program to demonstrate runtime polymorphism using an array of base 
class pointers.

Define a base class Shape with:

A pure virtual function area().
A virtual destructor.
Create two derived classes Circle and Rectangle:

Circle has a radius and calculates the area as π * r * r.
Rectangle has a width and height and calculates the area as width * height.
In the main() function:

Create an array of Shape* pointers.
Dynamically allocate objects of Circle and Rectangle.
Call the area() function for each object using the base class pointer.*/


#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
    virtual void area() = 0;  // Pure virtual function
    virtual ~Shape() {}      // Virtual destructor
};

class Circle : public Shape {
    int radius;

public:
    Circle(int r) : radius(r) {}  // Constructor to initialize radius

    void area() override {
        float area = 3.1416 * radius * radius;
        cout << "Circle Area: " << area << endl;
    }
};

class Rectangle : public Shape {
    int width, height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}  // Constructor to initialize width and height

    void area() override {
        float area = width * height;
        cout << "Rectangle Area: " << area << endl;
    }
};

int main() {
    // Array of base class pointers
    Shape* shapes[2];

    // Dynamically allocate derived class objects
    shapes[0] = new Circle(5);       // Circle with radius 5
    shapes[1] = new Rectangle(4, 6); // Rectangle with width 4 and height 6

    // Call area() function using base class pointers
    for (int i = 0; i < 2; ++i) {
        shapes[i]->area();
    }

    // Deallocate memory
    for (int i = 0; i < 2; ++i) {
        delete shapes[i];
    }

    return 0;
}

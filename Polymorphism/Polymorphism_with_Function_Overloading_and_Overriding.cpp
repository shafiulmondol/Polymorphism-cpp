/*Explain the difference between function overloading and function overriding in C++. 
Provide examples to demonstrate both concepts in a program. Include the following:

Use function overloading for multiple display() functions in a class Printer.
Use function overriding with a base class Printer and derived classes InkjetPrinter 
and LaserPrinter, implementing a virtual print() function.*/

#include <iostream>
#include <string>
using namespace std;

// Function Overloading Example
class Printer {
public:
    // Overloaded display() functions
    void display() {
        cout << "Displaying general printer information." << endl;
    }

    void display(string model) {
        cout << "Displaying information for model: " << model << endl;
    }

    void display(string model, int pagesPerMinute) {
        cout << "Model: " << model << ", Pages Per Minute: " << pagesPerMinute << endl;
    }
};

// Function Overriding Example
class BasePrinter {
public:
    virtual void print() {
        cout << "Base Printer: Printing in standard mode." << endl;
    }

    virtual ~BasePrinter() {}
};

class InkjetPrinter : public BasePrinter {
public:
    void print() override {
        cout << "Inkjet Printer: Printing with high-quality ink." << endl;
    }
};

class LaserPrinter : public BasePrinter {
public:
    void print() override {
        cout << "Laser Printer: Printing at high speed with toner." << endl;
    }
};

int main() {
    // Demonstrate Function Overloading
    Printer printer;
    printer.display();
    printer.display("HP DeskJet");
    printer.display("Canon Pixma", 20);

    cout << "\n--- Function Overriding Example ---\n";

    // Demonstrate Function Overriding
    BasePrinter* basePtr;

    InkjetPrinter inkjet;
    LaserPrinter laser;

    basePtr = &inkjet;
    basePtr->print(); // Calls InkjetPrinter::print()

    basePtr = &laser;
    basePtr->print(); // Calls LaserPrinter::print()

    return 0;
}

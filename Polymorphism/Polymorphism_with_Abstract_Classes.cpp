/*Create an abstract base class Employee with:

Protected data members: name (string), id (int).
A pure virtual function calculateSalary().
Create two derived classes:

Manager with a fixed monthly salary.
Salesperson with a base salary and commission.
Write a program to:

Accept details for both types of employees.
Use a base class pointer to display their names and salaries.*/

#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Employee {
protected:
    string name;
    int id;

public:
    virtual void calculateSalary() = 0; // Pure virtual function
    virtual ~Employee() {}             // Virtual destructor
};

// Derived Class: Manager
class Manager : public Employee {
    int fixedSalary;

public:
    Manager(string n, int i, int salary) {
        name = n;
        id = i;
        fixedSalary = salary;
    }

    void calculateSalary() override {
        cout << "Name: " << name << ", ID: " << id
             << ", Salary: " << fixedSalary << endl;
    }
};

// Derived Class: Salesperson
class Salesperson : public Employee {
    int baseSalary;
    int commission;

public:
    Salesperson(string n, int i, int base, int comm) {
        name = n;
        id = i;
        baseSalary = base;
        commission = comm;
    }

    void calculateSalary() override {
        int totalSalary = baseSalary + commission;
        cout << "Name: " << name << ", ID: " << id
             << ", Salary: " << totalSalary << endl;
    }
};

int main() {
    // Array of base class pointers
    Employee* employees[2];

    // Create Manager and Salesperson objects dynamically
    employees[0] = new Manager("Shafiul", 101, 50000);            // Manager with fixed salary
    employees[1] = new Salesperson("Mondol", 102, 30000, 5000);    // Salesperson with base salary and commission

    // Display details using base class pointer
    cout << "Employee Details:\n";
    for (int i = 0; i < 2; i++) {
        employees[i]->calculateSalary(); // Polymorphic call
    }

    // Cleanup
    for (int i = 0; i < 2; i++) {
        delete employees[i];
    }

    return 0;
}

/*Write a program to demonstrate polymorphism by simulating a file processing system:

Define a base class File with:

A pure virtual function open().
A virtual function close().
Create two derived classes:

TextFile to represent .txt files.
BinaryFile to represent .bin files.
In the main() function:

Create an array of base class pointers to File.
Dynamically allocate objects of TextFile and BinaryFile.
Use the base class pointers to call open() and close() functions.*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Base Class: File
class File {
public:
    virtual void open() = 0;   // Pure virtual function
    virtual void close() {     // Virtual function
        cout << "File closed." << endl;
    }
    virtual ~File() {}         // Virtual destructor
};

// Derived Class: TextFile
class TextFile : public File {
    ofstream file;
    string filename;

public:
    TextFile(string name) : filename(name) {}

    void open() override {
        file.open(filename, ios::app);
        if (file.is_open()) {
            cout << "Text file \"" << filename << "\" opened successfully." << endl;
        } else {
            cout << "Failed to open text file \"" << filename << "\"." << endl;
        }
    }

    void close() override {
        if (file.is_open()) {
            file.close();
            cout << "Text file \"" << filename << "\" closed successfully." << endl;
        } else {
            cout << "Text file \"" << filename << "\" was not open." << endl;
        }
    }
};

// Derived Class: BinaryFile
class BinaryFile : public File {
    ofstream file;
    string filename;

public:
    BinaryFile(string name) : filename(name) {}

    void open() override {
        file.open(filename, ios::binary | ios::app);
        if (file.is_open()) {
            cout << "Binary file \"" << filename << "\" opened successfully." << endl;
        } else {
            cout << "Failed to open binary file \"" << filename << "\"." << endl;
        }
    }

    void close() override {
        if (file.is_open()) {
            file.close();
            cout << "Binary file \"" << filename << "\" closed successfully." << endl;
        } else {
            cout << "Binary file \"" << filename << "\" was not open." << endl;
        }
    }
};

int main() {
    // Array of base class pointers
    File* files[2];

    // Dynamically allocate objects for TextFile and BinaryFile
    files[0] = new TextFile("example.txt");
    files[1] = new BinaryFile("example.bin");

    // Open and close files using polymorphism
    for (int i = 0; i < 2; i++) {
        files[i]->open();
        files[i]->close();
        cout << endl;
    }

    // Cleanup
    for (int i = 0; i < 2; i++) {
        delete files[i];
    }

    return 0;
}

/*Define a base class Animal with the following:

A pure virtual function makeSound().
A non-virtual function info() to display "I am an Animal."
Create two derived classes Dog and Cat, each overriding the makeSound() function:

Dog should print "Woof!".
Cat should print "Meow!".
Write a program to:

Use a base class pointer to invoke makeSound() for both derived class objects.
Demonstrate the difference between the virtual function and non-virtual function.*/

#include <iostream>
#include <string>
using namespace std;

class Animal{
public:
virtual void makeSound()=0;
void info(){
    cout<<"I am an Animal.";
}
};

class Dog:public Animal{
public:
void makeSound(){
    cout <<"Woof!"<<endl;
}
};

class Cat: public Animal{
public: 
void makeSound(){
    cout <<"Meow!"<<endl;
}
};

int main(){
Animal *ptr;
ptr=new Dog;
    ptr->makeSound();
ptr= new Cat;
    ptr->makeSound();

        ptr->info(); // Calls the base class version of info()
}

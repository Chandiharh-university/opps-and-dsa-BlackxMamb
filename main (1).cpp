#include <iostream>
using namespace std;

// Base class
class Base {
public:
    virtual void display() {
        cout << "Display from Base class" << endl;
    }
};

// Derived class
class Derived : public Base {
public:
    void display() override { // Function overriding
        cout << "Display from Derived class" << endl;
    }
};

int main() {
    Base* basePtr;       // Pointer to Base class
    Derived derivedObj;  // Object of Derived class

    basePtr = &derivedObj;

    // Call display function
    basePtr->display();  // Calls Derived class's display method due to polymorphism

    return 0;
}
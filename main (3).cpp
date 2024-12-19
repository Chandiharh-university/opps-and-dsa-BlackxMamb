#include <iostream>
using namespace std;

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to add three integers
int add(int a, int b, int c) {
    return a + b + c;
}

// Function to add two floating-point numbers
float add(float a, float b) {
    return a + b;
}

// Function to concatenate two strings
string add(string a, string b) {
    return a + b;
}

int main() {
    // Adding two integers
    cout << "Sum of 5 and 10: " << add(5, 10) << endl;

    // Adding three integers
    cout << "Sum of 5, 10, and 15: " << add(5, 10, 15) << endl;

    // Adding two floats
    cout << "Sum of 5.5 and 10.5: " << add(5.5f, 10.5f) << endl;

    // Concatenating two strings
    cout << "Concatenation of 'Hello' and ' World': " << add(string("Hello"), string(" World")) << endl;

    return 0;
}

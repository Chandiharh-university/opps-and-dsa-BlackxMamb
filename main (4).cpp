#include <iostream>
#include <string>
using namespace std;

int main() {
    // Declare and initialize strings
    string str1 = "Hello";
    string str2 = "World";
    string str3;

    // Concatenation
    str3 = str1 + " " + str2;
    cout << "Concatenated String: " << str3 << endl;

    // Find length of a string
    cout << "Length of '" << str3 << "': " << str3.length() << endl;

    // Access characters in a string
    cout << "First character of str1: " << str1[0] << endl;

    // Modify a character in the string
    str1[0] = 'h';
    cout << "Modified str1: " << str1 << endl;

    // Compare strings
    if (str1 == str2) {
        cout << str1 << " is equal to " << str2 << endl;
    } else {
        cout << str1 << " is not equal to " << str2 << endl;
    }

    // Substring
    string substring = str3.substr(6, 5); // Extracts "World"
    cout << "Substring from str3: " << substring << endl;

    // Find a substring
    size_t pos = str3.find("World");
    if (pos != string::npos) {
        cout << "'World' found at position: " << pos << endl;
    } else {
        cout << "'World' not found!" << endl;
    }

    // Clear a string
    str3.clear();
    cout << "Cleared string str3: '" << str3 << "'" << endl;

    // Check if a string is empty
    if (str3.empty()) {
        cout << "str3 is empty!" << endl;
    }

    return 0;
}

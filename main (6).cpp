#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int* arr = new int[SIZE]();  
    arr[1] = 10;
    arr[3] = 20;
    arr[4] = 30;
    arr[5] = 40;
    arr[6] = 50;
    cout << "Memory addresses of array elements:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "arr[" << i << "] = " << arr[i] << ", Address: " << &arr[i] << endl;
    }
    delete[] arr;
    return 0;
}

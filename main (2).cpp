#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}
int sumOfPrimes(int n) {
    int sum = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = sumOfPrimes(n);
    cout << "The sum of prime numbers up to " << n << " is: " << result << endl;

    return 0;
}

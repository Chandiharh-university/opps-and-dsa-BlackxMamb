#include <iostream>
#include <vector>
using namespace std;

// Function to print a vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Recursive function to generate numbers with a given sum
void generateNumbersWithSum(int targetSum, int start, vector<int>& currentCombination) {
    if (targetSum == 0) {
        // Print the current combination if it matches the target sum
        printVector(currentCombination);
        return;
    }

    for (int i = start; i <= targetSum; i++) {
        currentCombination.push_back(i);      // Include the current number
        generateNumbersWithSum(targetSum - i, i, currentCombination); // Recur with reduced sum
        currentCombination.pop_back();        // Backtrack to explore other combinations
    }
}

int main() {
    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    vector<int> currentCombination;
    cout << "Combinations that sum to " << targetSum << ":" << endl;
    generateNumbersWithSum(targetSum, 1, currentCombination);

    return 0;
}

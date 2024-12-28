#include <iostream>
#include <vector>
using namespace std;

// Helper function to generate combinations using backtracking
void backtrack(int start, int n, int k, vector<int>& currentCombination, vector<vector<int>>& result) {
    // Base case: if the combination has k elements, add it to the result
    if (currentCombination.size() == k) {
        result.push_back(currentCombination);
        return;
    }

    // Explore all numbers starting from 'start'
    for (int i = start; i <= n; i++) {
        currentCombination.push_back(i);          // Include the current number
        backtrack(i + 1, n, k, currentCombination, result); // Recur for the next numbers
        currentCombination.pop_back();            // Backtrack by removing the last number
    }
}

// Function to generate all combinations
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> currentCombination;
    backtrack(1, n, k, currentCombination, result); // Start backtracking from 1
    return result;
}

int main() {
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    vector<vector<int>> combinations = combine(n, k);

    cout << "Combinations of " << k << " numbers chosen from 1 to " << n << " are:" << endl;
    for (const auto& combination : combinations) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); i++) {
            cout << combination[i];
            if (i != combination.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }

    return 0;
}

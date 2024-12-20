#include <iostream>
#include <vector>
#include <algorithm> // For sort()

using namespace std;

// Bucket Sort function
void bucketSort(int arr[], int n) {
    // Step 1: Find the maximum element to determine bucket range
    int maxVal = *max_element(arr, arr + n);

    // Step 2: Create buckets (one bucket for each range)
    int bucketCount = maxVal / 5 + 1; // Adjust bucket size for the data range
    vector<vector<int>> buckets(bucketCount);

    // Step 3: Place array elements into their respective buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / 5; // Adjust division factor based on range
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Step 4: Sort individual buckets
    for (int i = 0; i < bucketCount; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Step 5: Concatenate all buckets into the original array
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int arr[] = {6, 7, 3, 1, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bucketSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Function to count frequency of each element in the array
void countFreq(int arr[], int n) {
    // Create a visited array to mark elements that are already processed
    vector<bool> visited(n, false);

    // Traverse through all elements of the array
    for (int i = 0; i < n; i++) {
        // Skip this element if it's already processed
        if (visited[i] == true)
            continue;

        // Count the frequency of arr[i]
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true; // Mark arr[j] as processed
                count++;
            }
        }

        // Output the element and its count
        cout << arr[i] << " " << count << endl;
    }
}

int main() {
    // Input array
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the function to count frequencies
    countFreq(arr, n);
    return 0;
}
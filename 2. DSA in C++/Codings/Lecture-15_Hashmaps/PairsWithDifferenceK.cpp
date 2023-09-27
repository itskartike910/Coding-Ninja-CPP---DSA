#include <iostream>
using namespace std;

// #include "solution.h"

#include <unordered_map>
#include <iostream>
using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k) {
    unordered_map<int, int> elementCount;
    int count = 0;

    // Count the frequency of each element in the array
    for (int i = 0; i < n; i++) {
        elementCount[arr[i]]++;
    }

    // Iterate through the array and find pairs with a difference of K
    for (int i = 0; i < n; i++) {
        int currentElement = arr[i];
        int target1 = currentElement + k;
        int target2 = currentElement - k;

        // Check if there's a valid pair with difference K
        if (k == 0) {
            // Handle the special case where K is 0
            if (elementCount[currentElement] >= 2) {
                count++;
            }
        } else {
            if (elementCount.find(target1) != elementCount.end()) {
                count++;
            }
            if (elementCount.find(target2) != elementCount.end()) {
                count++;
            }
        }

        // Mark the current element as visited to avoid duplicate counting
        elementCount[currentElement] = 0;
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}
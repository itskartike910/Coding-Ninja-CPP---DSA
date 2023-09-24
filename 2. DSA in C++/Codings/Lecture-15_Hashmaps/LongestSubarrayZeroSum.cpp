#include <iostream>
using namespace std;

// #include "solution.h"

#include <unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int, int> prefixSumMap;
    int maxLen = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If the current sum is zero, it means the subarray from the beginning has a sum of zero.
        if (sum == 0) {
            maxLen = i + 1;
        }

        // If the sum has been seen before, it means the subarray between the two occurrences has a sum of zero.
        if (prefixSumMap.find(sum) != prefixSumMap.end()) {
            maxLen = max(maxLen, i - prefixSumMap[sum]);
        } else {
            // Store the index of the first occurrence of the sum in the map.
            prefixSumMap[sum] = i;
        }
    }

    return maxLen;
}


int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}
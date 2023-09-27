#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    vector<int> result;
    unordered_set<int> numSet;

    // Add all elements to the hash set
    for (int i = 0; i < n; i++) {
        numSet.insert(arr[i]);
    }

    int maxLength = 0;
    int currentStart = arr[0];

    for (int i = 0; i < n; i++) {
        int currentNum = arr[i];

        // Check if the current number is the start of a sequence
        if (numSet.find(currentNum - 1) == numSet.end()) {
            int currentLength = 1;
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentLength++;
            }

            // Update the result if the current sequence is longer
            if (currentLength > maxLength) {
                maxLength = currentLength;
                currentStart = currentNum - currentLength + 1;
            }
        }
    }

    // Populate the result vector
    for (int i = currentStart; i < currentStart + maxLength; i++) {
        result.push_back(i);
    }
    
    return {result[0],result[result.size()-1]};
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;

    return 0;
}

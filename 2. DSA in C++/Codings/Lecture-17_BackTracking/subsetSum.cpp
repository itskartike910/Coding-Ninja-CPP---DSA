#include <bits/stdc++.h>
using namespace std;

void subsetSum(vector<int> &vec, int n, int k, int &count, int index = 0, int currSum = 0) {
    if (index == n) {
        if (currSum == k) {
            count++;
        }
        return;
    }
    // Include the current element and move to the next element
    subsetSum(vec, n, k, count, index + 1, currSum + vec[index]);

    // Exclude the current element and move to the next element
    subsetSum(vec, n, k, count, index + 1, currSum);
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        int count = 0;
        subsetSum(vec, n, k, count);
        cout << count << endl;
    }
    return 0;
}

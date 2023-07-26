#include <iostream>
#include <algorithm>
using namespace std;

int tripletSum(int* arr, int n, int target) {
    // Function implementation for tripletSum goes here
    // ...
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int size;
        int x;
        cin >> size;

        int* input = new int[size];

        for (int i = 0; i < size; i++) {
            cin >> input[i];
        }
        cin >> x;

        cout << tripletSum(input, size, x) << endl;

        delete[] input;
    }

    return 0;
}
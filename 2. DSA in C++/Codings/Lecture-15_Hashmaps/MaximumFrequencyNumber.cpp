#include <iostream>
using namespace std;

// #include "solution.h"

#include<unordered_map>
int highestFrequency(int arr[], int n) {
    // Write your code here
    int maxFreq=0,element;
    unordered_map<int, int > mp;
    for (int i = 0; i < n; i++) {
      mp[arr[i]]++;
    }
    for (int i = 0; i < n; i++){
        if(mp.at(arr[i])>maxFreq){ 
            maxFreq = mp.at(arr[i]);
            element = arr[i];
        }
    }
    return element;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}
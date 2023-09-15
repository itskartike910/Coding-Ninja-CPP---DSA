#include <iostream>
using namespace std;

// #include "solution.h"

#include<unordered_map>
int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int,int> mp;
    int count=0;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        int element=arr[i];
        int neg = -1 * element;
        if(mp[neg]>0){
            count+=mp[neg];
            mp[neg]=0;
            mp[element]--;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}
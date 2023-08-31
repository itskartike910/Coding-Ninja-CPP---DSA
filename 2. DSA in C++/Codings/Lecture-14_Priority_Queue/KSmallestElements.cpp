#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// #include "solution.h"

#include<bits/stdc++.h>
vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    vector<int> vec;
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(!pq.empty()){
        vec.push_back(pq.top());
        pq.pop();
    }
    return vec;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
}
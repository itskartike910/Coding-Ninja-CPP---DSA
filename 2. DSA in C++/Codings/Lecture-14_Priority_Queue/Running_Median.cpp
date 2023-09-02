#include <iostream>
using namespace std;

// #include "solution.h"

//Time Complexity = O(n2) -> Not optimal
#include <bits/stdc++.h>
void findMedian(int *arr, int n){
    // Write your code here
    priority_queue<int,vector<int> , greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        priority_queue<int,vector<int> , greater<int>> temp = pq;
        vector<int> vec;
        while(!temp.empty()){
            vec.push_back(temp.top());
            temp.pop();
        }
        int s = vec.size();
        if(s%2){
            cout<<vec[s/2]<<" ";
        }
        else{
            cout<<(vec[(s/2)-1]+vec[(s)/2])/2<<" ";
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}

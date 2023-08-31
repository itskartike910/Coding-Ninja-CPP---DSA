#include <iostream>
#include <vector>
using namespace std;

// #include "solution.h"

#include <bits/stdc++.h>
int buyTicket(int *arr, int n, int k) {
    // Write your code here
    int time=0;
    priority_queue<int> pq;
    queue<int> q;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        q.push(arr[i]);
    }
    // for(int i=0;i<n;i++){
    //     if(q.front()==pq.top()){
    //         q.pop();
    //         pq.pop();
    //         time++;
    //         k--;
    //     }
    //     else{
    //         int x=q.front();
    //         if(k==0 && arr[k]==q.front()) k=q.size()-1;
    //         else k--;
    //         q.pop();
    //         q.push(x);
    //     }
    //     if(k==-1) break;
    // }
    int x=k;
    int val = arr[x];
    while(!q.empty()){
        if(pq.top()==q.front()){
            q.pop();
            pq.pop();
            time++;
            x--;
        }
        else{
            int y = q.front();
            if(y==val && x==0) x=q.size()-1;
            else x--;
            q.pop();
            q.push(y);
        }
        if(x==-1) break;
    }
    return time;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}
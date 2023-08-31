#include <bits/stdc++.h>
using namespace std;

void KSortedArray(int *vec,int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(vec[i]);
    }
    int j=0;
    for(int i=k;i<n;i++){
        vec[j]=pq.top();
        pq.pop();
        pq.push(vec[i]);
        j++;
    }
    while(!pq.empty()){
        vec[j]=pq.top();
        pq.pop();
        j++;
    }
}

int main(){
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    KSortedArray(arr,n,k);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
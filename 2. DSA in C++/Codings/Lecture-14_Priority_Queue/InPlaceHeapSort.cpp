#include <iostream>
// #include "solution.h"

//Without using space O(n^2)
/*
#include<bits/stdc++.h>
using namespace std;
void heapSort(int arr[], int n) {
    // Write your code
    //Building a heap using array
    for(int i=1;i<n;i++){
        int childIndex = i;
        while(childIndex>0){
            int parentIndex = (childIndex-1)/2;
            if(arr[parentIndex]>arr[childIndex]){
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[childIndex];
                arr[childIndex] = temp;
            }
            else{
                break;
            }
            childIndex=parentIndex;
        }
    }
    //Down heapify
    int size = n;
    swap(arr[0],arr[n-1]);
    size--;
    int PI = 0;
    while(PI<size){
        int leftChildIndex = 2 * PI + 1;
        int rightChildIndex = 2 * PI + 2;
        int minIndex = PI;

        if (leftChildIndex < size && arr[leftChildIndex] < arr[minIndex]) {
            minIndex = leftChildIndex;
        }
        if (rightChildIndex < size && arr[rightChildIndex] < arr[minIndex]) {
            minIndex = rightChildIndex;
        }
        if (minIndex == PI) {
            break;
        } 
        else {
            int temp = arr[PI];
            arr[PI] = arr[minIndex];
            arr[minIndex] = temp;
            PI = minIndex;
        }
    }
}
*/
// With using space O(n^2)
#include<bits/stdc++.h>
using namespace std;
void heapSort(int arr[], int n) {
    // Write your code
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        arr[i] = pq.top();
        pq.pop();
    }
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}
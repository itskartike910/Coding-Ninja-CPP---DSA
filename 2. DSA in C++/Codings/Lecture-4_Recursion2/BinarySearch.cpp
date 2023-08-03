#include <iostream>
// #include "solution.h"
using namespace std;

int binarySearchRecursive(int input[], int low, int high, int element) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (input[mid] == element)
            return mid;

        if (input[mid] > element)
            return binarySearchRecursive(input, low, mid - 1, element);

        return binarySearchRecursive(input, mid + 1, high, element);
    }
    return -1;
}
int binarySearch(int input[], int size, int element) {
    return binarySearchRecursive(input, 0, size - 1, element);
}


int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}

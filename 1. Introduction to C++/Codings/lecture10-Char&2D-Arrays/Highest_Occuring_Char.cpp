#include <iostream>
#include <cstring>
using namespace std;

// #include "solution.h"
char highestOccurringChar(char input[]) {
    // Write your code here
    int n = strlen(input);
    int *arr = new int[n],count=0;
    for(int i=0;i<n;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(input[i]==input[j]){
                count++;
            }
        }
        arr[i]=count;
    }
    int max=arr[0],index=0;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
            index=i;
        }
    }
    delete(arr);
    return input[index];
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << highestOccurringChar(str);
}
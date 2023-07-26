#include <iostream>
// #include "solution.h"
using namespace std;

// Change in the given string itself. So no need to return or print anything

#include <bits/stdc++.h>

void leftShiftbyOne(char arr[],int startIdx){
    int n = strlen(arr);
    for(int i=startIdx;i<n;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]='\0';
}

void removeX(char input[] , int start = 0) {
    // Write your code here
    if (input[start] == '\0' ) {
        return;
    }
    if(input[start]=='x'){
        leftShiftbyOne(input, start);
        removeX(input, start);
    }
    else{
        removeX(input, start + 1);
    }
}


int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}

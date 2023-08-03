#include <iostream>
#include <bits/stdc++.h>
// #include "solution.h"
using namespace std;

// Change in the given string itself. So no need to return or print the changed string.

void rightShiftFromIndex(char arr[], int startIdx) {
    int n = strlen(arr);
    for (int i = n ; i > startIdx; --i)
        arr[i] = arr[i - 1];
    arr[n+1]='\0';
}

void pairStar(char input[],int index = 0) {
    // Write your code here
    if (input[index] == '\0' ){
        return;
    }
    if(input[index]==input[index+1]){
        rightShiftFromIndex(input,index+1);
        input[index+1]='*';
        pairStar(input,index+2);
    }
    else{
        pairStar(input,index+1);
    }
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}

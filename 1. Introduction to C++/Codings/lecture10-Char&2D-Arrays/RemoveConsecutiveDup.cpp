#include <iostream>
#include <cstring>
using namespace std;

// #include "solution.h"
void removeConsecutiveDuplicates(char input[]) {
    // Write your code here
    int n = strlen(input),j=0;
    char arr[n];
    arr[0]=input[0];
    for(int i=0;i<n;i++){
        if(input[i]!=arr[j]){
            j++;
            arr[j]=input[i];
        }
    }
    arr[j+1]='\0';
    strcpy(input,arr);
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str ;
}
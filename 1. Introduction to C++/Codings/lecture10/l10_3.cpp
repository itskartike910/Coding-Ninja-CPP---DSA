#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

// #include "solution.h"
void trimSpaces(char input[]) {
    // Write your code here
    char *arr = new char[1000000];
    for(int i=0,j=0;input[i]!='\0';){
        if(input[i]==' '){
            i++;
        }
        else{
            arr[j] = input[i];
            i++;
            j++;
        }
    }
    for(int i=0;input[i]!='\0';i++){
        if(arr[i]=='\0'){
            input[i] = '\0';
            break;
        }else{
            input[i] = arr[i];
        }
    }
    delete(arr);
}

int main() {
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}


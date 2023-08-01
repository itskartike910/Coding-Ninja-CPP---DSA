#include <iostream>
#include <cstring>
using namespace std;

// #include "solution.h"
void removeAllOccurrencesOfChar(char input[], char c) {
    // Write your code here
    int n = strlen(input);
    char *output = new char[n];
    int j=0;
    for(int i=0;i<n;i++){
        if(input[i]!=c){
            output[j++]=input[i];
        }
    }
    output[j]='\0';
    for(int i=0;i<n;i++){
        input[i]=output[i];
    }
    delete(output);
}


int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    char c;
    cin >> c;
    removeAllOccurrencesOfChar(str, c);
    cout << str;
}
#include <iostream>
#include <cstring>
using namespace std;

// #include "solution.h"
void printSubstrings(char input[]) {
    // Write your code here
    int n = strlen(input);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++)
                cout<<input[k];
            cout<<endl;
        }
    }
    
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}
#include <iostream>
#include<bits/stdc++.h>
#include <cstring>
using namespace std;

// #include "solution.h"
bool isPermutation(char input1[], char input2[]) {
    // Write your code here
    int x=strlen(input1);
    int y=strlen(input2);
    int flag=0;
    // int freq[256]={0};
    if(x!=y) return false;
    else{
        for(int i=0;i<x;i++){
            flag=0;
            for(int j=0;j<y;j++){
                if(input1[i]==input2[j]){
                    flag=1;
                    break;
                }
                else flag=0;
            }
            if(flag==0){
                return false;
            }
        }
        if(flag==1) return true;
    }
}

int main() {
    int size = 1e6;
    char input1[size];
    char input2[size];
    cin >> input1 >> input2;
    cout << (isPermutation(input1, input2) ? "true" : "false");
}
#include <iostream>
#include <cstring>
using namespace std;

// #include "solution.h"
void reverseEachWord(char input[]) {
    // Write your code here
    int n = strlen(input);
    char *output = new char[n];
    int i=0,j=0,s=0;
    while(j<=n){
        if(input[j]==' ' || input[j]=='\0'){
            for(int k=j-1;k>=s;k--){
                output[i++]=input[k];
            }
            s=j+1;
            j++;
            output[i++]=' ';
        }
        else{
            j++;
        }
    }
    for(int m=0;m<n;m++){
        input[m]=output[m];
    }
    delete(output);
}

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}
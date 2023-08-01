#include <iostream>
#include <cstring>
using namespace std;

// #include "solution.h"

bool checkPalindrome(char str[]) {
    // Write your code here
    int flag=0,n;
    for(n=1;str[n]!='\0';n++);
    if(n==1)    return true;
    else if(n==0)   return false;
    else{
        for(int i=0;i<n/2;i++){
          if (str[i] == str[n - i - 1]) {
            flag = 1;
          } else
            flag = 0;
        }
        return (flag == 1) ? true : false;
    }
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");
}
#include <iostream>
// #include "solution.h"
using namespace std;

#include <bits/stdc++.h>

bool isPalindrome(char *s, int start, int end) {
    if (start >= end) {
        return true;
    }

    if (s[start] != s[end]) {
        return false;
    }
    return isPalindrome(s, start + 1, end - 1);
}


bool checkPalindrome(char input[]) {
    // Write your code here
    int length = strlen(input);
    return isPalindrome(input, 0, length - 1);
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

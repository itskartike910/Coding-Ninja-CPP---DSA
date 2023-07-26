#include <iostream>
// #include "solution.h"
using namespace std;

#include <string.h>
#include <bits/stdc++.h>
using namespace std;

void getCodesHelper(string input, string code, vector<string>& result) {
    if (input.empty()) {
        result.push_back(code);
        return;
    }
    
    // Taking the first character as a single digit code
    int singleDigit = input[0] - '0';
    char singleChar = 'a' + singleDigit - 1;
    getCodesHelper(input.substr(1), code + singleChar, result);
    
    // Taking the first two characters as a double digit code
    if (input.length() >= 2) {
        int doubleDigit = stoi(input.substr(0, 2));
        if (doubleDigit >= 10 && doubleDigit <= 26) {
            char doubleChar = 'a' + doubleDigit - 1;
            getCodesHelper(input.substr(2), code + doubleChar, result);
        }
    }
}

void printAllPossibleCodes(string input) {
    vector<string> result;
    getCodesHelper(input, "", result);
    
    for (const string& code : result) {
        cout << code << endl;
    }
}


int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}

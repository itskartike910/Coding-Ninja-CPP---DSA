#include <iostream>
#include <bits/stdc++.h>
#include <string>
// #include "solution.h"
using namespace std;

//Code By ME
// int count_digits(int num){
//     if(num<=0) return 0;
//     else{
//         return 1 + count_digits(num/10);
//     }
// }

// void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    // string input;
    // if(num==0 || num==1){
    //     cout<<""<<endl;
    //     return ;
    // } 
    // int n=num%10;
    // switch(n){
    //     case 0||1: input = "";
    //         break;
    //     case 2: input = "abc";
    //         break;
    //     case 3: input = "def";
    //         break;
    //     case 4: input = "ghi";
    //         break;
    //     case 5: input = "jkl";
    //         break;
    //     case 6: input = "mno";
    //         break;
    //     case 7: input = "pqrs";
    //         break;
    //     case 8: input = "tuv";
    //         break;
    //     case 9: input = "wxyz";
    //         break;
    // }
    // int maxsize = pow(4,count_digits(num));
    // string *str = new string[maxsize];
    // int k=0;
    // for(int i=0; i<maxsize; i++){
    //     for(int j=0; j<input.size(); j++){
    //         str[k] = str[i]+input[j];
    //         k++;
    //     }

// }

//Code by chatGPT
void printKeypadUtil(string num, vector<string>& keypadCombinations, string currentCombination, int index, int n) {
    // Base case: if all digits of the number have been processed
    if (index == n) {
        keypadCombinations.push_back(currentCombination);
        return;
    }

    // Get the character set corresponding to the current digit
    string keypad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string characters = keypad[num[index] - '0'];

    // Recursively generate combinations for the remaining digits
    for (int i = 0; i < characters.length(); i++) {
        currentCombination[index] = characters[i];
        printKeypadUtil(num, keypadCombinations, currentCombination, index + 1, n);
    }
}

// Function to print all possible combinations of keypad
void printKeypad(int num) {
    string numString = to_string(num);
    int n = numString.length();
    vector<string> keypadCombinations;

    string currentCombination(n, ' '); // Initialize a string with n spaces

    // Generate keypad combinations using recursion
    printKeypadUtil(numString, keypadCombinations, currentCombination, 0, n);

    // Print the generated keypad combinations
    for (string combination : keypadCombinations) {
        cout << combination << endl;
    }
}

int main(){
    int num;
    cin >> num;
    printKeypad(num);
    return 0;
}

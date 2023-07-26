#include <iostream>
#include <string>
// #include "solution.h"
using namespace std;

// Helper function to generate keypad strings
void generateKeypadStrings(int num, std::string output[], const std::string keypad[], std::string currentStr, int index, int& count) {
    // Base case: if all digits have been processed, add the current string to the output array
    if (num == 0) {
        output[index] = currentStr;
        count++;
        return;
    }
  
    // Extract the last digit from the number
    int lastDigit = num % 10;
  
    // Get the corresponding letters for the last digit from the keypad mapping
    std::string letters = keypad[lastDigit];
  
    // Iterate over each letter and generate strings for the remaining digits
    for (char c : letters) {
        generateKeypadStrings(num / 10, output, keypad, c + currentStr, index + count, count);
    }
}

int keypad(int num, std::string output[]) {
    // Mapping of digits to letters
    std::string keypad[] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };
  
    // Variable to keep track of the number of strings inserted into the output array
    int count = 0;
  
    // Generate keypad strings
    generateKeypadStrings(num, output, keypad, "", 0, count);
  
    return count;
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

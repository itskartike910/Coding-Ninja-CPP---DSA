#include <iostream>
// #include "solution.h"
using namespace std;

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Mapping of characters to their corresponding alphabet position
string mapping[] = {"0", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

int getCodes(string input, string output[10000]) {
    // Base case: if the input string is empty, return an empty string
    if (input.empty()) {
        output[0] = "";
        return 1;
    }

    // Recursive case: obtain the list of codes for the remaining input string
    string remainingInput = input.substr(1);
    string remainingOutput[10000];
    int remainingOutputCount = getCodes(remainingInput, remainingOutput);

    // Prepend the first character of the input string to each code obtained from the remaining input
    int currentDigit = input[0] - '0';
    int codesCount = 0;
    for (int i = 0; i < remainingOutputCount; i++) {
        for (int j = 0; j < mapping[currentDigit].length(); j++) {
            output[codesCount] = mapping[currentDigit][j] + remainingOutput[i];
            codesCount++;
        }
    }

    // If there are at least two digits remaining and the first two digits form a number less than or equal to 26,
    // prepend the character corresponding to the two-digit number to each code obtained from the remaining input
    if (input.length() >= 2) {
        int twoDigitNumber = (input[0] - '0') * 10 + (input[1] - '0');
        if (twoDigitNumber <= 26) {
            string remainingOutputTwoDigits[10000];
            int remainingOutputTwoDigitsCount = getCodes(input.substr(2), remainingOutputTwoDigits);
            for (int i = 0; i < remainingOutputTwoDigitsCount; i++) {
                for (int j = 0; j < mapping[twoDigitNumber].length(); j++) {
                    output[codesCount] = mapping[twoDigitNumber][j] + remainingOutputTwoDigits[i];
                    codesCount++;
                }
            }
        }
    }

    return codesCount;
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}

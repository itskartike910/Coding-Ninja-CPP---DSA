#include <iostream>
#include <string>
// #include "solution.h"
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

void findPermutations(const std::string& input, std::string output, std::vector<std::string>& permutations) {
    // Base case: If the input string is empty, add the current output string to the permutations vector
    if (input.empty()) {
        permutations.push_back(output);
        return;
    }

    // Recursive case: Generate permutations by fixing each character of the input string at the first position
    for (size_t i = 0; i < input.length(); ++i) {
        std::string newInput = input;
        std::string newOutput = output + newInput[i];
        newInput.erase(i, 1);  // Remove the selected character from the remaining input

        findPermutations(newInput, newOutput, permutations);
    }
}

int returnPermutations(const std::string& input, std::string output[]) {
    std::vector<std::string> permutations;
    findPermutations(input, "", permutations);

    // Copy the permutations to the output array
    int count = 0;
    for (const std::string& perm : permutations) {
        output[count++] = perm;
    }

    return count;  // Return the number of permutations
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

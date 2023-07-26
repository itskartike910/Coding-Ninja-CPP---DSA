#include <iostream>
#include <string>
using namespace std;

// #include "solution.h"

#include <iostream>
#include <string>
#include <algorithm>

void findPermutations(const std::string& input, std::string output, int index) {
    if (index == input.length()) {
        std::cout << output << "\n";
        return;
    }

    for (int i = index; i < input.length(); ++i) {
        std::swap(output[index], output[i]);
        findPermutations(input, output, index + 1);
        std::swap(output[index], output[i]);
    }
}

void printPermutations(const std::string& input) {
    std::string output = input;
    findPermutations(input, output, 0);
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
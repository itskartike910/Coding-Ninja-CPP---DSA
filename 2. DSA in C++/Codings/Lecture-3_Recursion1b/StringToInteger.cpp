#include <iostream>
#include <cstring>
// #include "solution.h"
using namespace std;

//Iteration

// int stringToNumber(char input[] , int index = 0) {
//     // Write your code here
//     int result = 0;
//     while(input[index] != '\0') {
//         result = result * 10 + (input[index] - '0');
//         index++;
//         }
//     return result;
// }

//Recursion

int stringToNumber(char input[] , int index = 0){
    // Write your code here
    int n = strlen(input);
    if(input[index] == '\0') return 0;
    return ((input[n-index-1] - '0') + 10 * stringToNumber(input,index+1));
}


int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}

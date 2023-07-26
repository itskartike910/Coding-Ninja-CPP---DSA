#include <iostream>
using namespace std;
// #include "solution.h"

//My Approach
// void printSubsetsOfArray(int input[], int n) {
// 	// Write your code here
//     if (n == 0) {
//         // cout<<""<<endl;
//         return ;
//     }
//     printSubsetsOfArray(input + 1, n - 1);
//     int j=1;
//     for(int i=0;i<n;i++){
//         cout<<input[0];
//         for(;j<=i;j++){
//             cout<<" "<<input[j];
//         }
//         cout<<endl;
//     }
// }

//GPT's Approach
void printSubsetsOfArray(int input[], int n, int subset[], int subsetSize, int index) {
    if (index == n) {
        // Base case: All elements have been considered
        for (int i = 0; i < subsetSize; i++) {
            cout << subset[i] << " ";
        }
        cout << endl;
        return;
    }

    // Recursive case: Include the current element in the subset
    subset[subsetSize] = input[index];
    printSubsetsOfArray(input, n, subset, subsetSize + 1, index + 1);

    // Recursive case: Exclude the current element from the subset
    printSubsetsOfArray(input, n, subset, subsetSize, index + 1);
}

void printSubsetsOfArray(int input[], int n) {
    int subset[20];
    printSubsetsOfArray(input, n, subset, 0, 0);
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}

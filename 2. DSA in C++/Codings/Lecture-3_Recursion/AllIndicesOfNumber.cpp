#include<iostream>
// #include "Solution.h"
using namespace std;

#include <bits/stdc++.h>

int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    // Base case: end of array
    if (size == 0) {
        return 0;
    }

    // Recursive call to search for x in the remaining array
    int smallOutputSize = allIndexes(input + 1, size - 1, x, output);

    // Adjust the indexes in the output array for the remaining part
    for (int i = 0; i < smallOutputSize; i++) {
        output[i] = output[i] + 1;
    }

    // Check if x is found at the current index
    if (input[0] == x) {
        // Shift the indexes in the output array
        for (int i = smallOutputSize; i > 0; i--) {
            output[i] = output[i - 1];
        }
        // Add the current index to the output array
        output[0] = 0;
        return smallOutputSize + 1;
    } else {
        return smallOutputSize;
    }
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}



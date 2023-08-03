#include <iostream>
// #include "solution.h"
using namespace std;

int subsetSumToKUtil(int input[], int n, int output[][50], int k, int currSum, int start, int subset[], int subsetSize, int row) {
    if (currSum == k) {
        output[row][0] = subsetSize; // Set the length of the subset in the first column
        for (int i = 0; i < subsetSize; i++) {
            output[row][i + 1] = subset[i]; // Save the subset in the remaining columns
        }
        return 1; // Return 1 to indicate one subset is found
    }
    if (start == n)
        return 0; // Return 0 to indicate no subset is found

    int count = 0;
    for (int i = start; i < n; i++) {
        subset[subsetSize] = input[i];
        count += subsetSumToKUtil(input, n, output, k, currSum + input[i], i + 1, subset, subsetSize + 1, row + count);
    }
    return count;
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    int subset[50];
    return subsetSumToKUtil(input, n, output, k, 0, 0, subset, 0, 0);
}


int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}

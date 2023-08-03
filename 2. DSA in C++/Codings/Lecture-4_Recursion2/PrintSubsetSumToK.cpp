#include <iostream>
#include <vector>

using namespace std;

void printSubsetSumToKUtil(int input[], int size, int k, vector<int>& subset, int currIndex, int currSum) {
    if (currIndex == size) {
        if (currSum == k) {
            // Print the subset
            for (int i = 0; i < subset.size(); i++) {
                cout << subset[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    // Exclude the current element
    printSubsetSumToKUtil(input, size, k, subset, currIndex + 1, currSum);

    // Include the current element
    subset.push_back(input[currIndex]);
    printSubsetSumToKUtil(input, size, k, subset, currIndex + 1, currSum + input[currIndex]);

    // Backtrack
    subset.pop_back();
}

void printSubsetSumToK(int input[], int size, int k) {
    vector<int> subset;
    printSubsetSumToKUtil(input, size, k, subset, 0, 0);
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}

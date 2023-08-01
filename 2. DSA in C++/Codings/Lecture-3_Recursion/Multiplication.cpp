#include <iostream>
// #include "solution.h"
using namespace std;

int multiplyNumbers(int m, int n) {
    // Write your code here
    if(n==0) return 0;
    int ans = m + multiplyNumbers(m, n-1);
    return ans;
}


int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;

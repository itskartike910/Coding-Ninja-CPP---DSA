#include <iostream>
// #include "solution.h"
using namespace std;

int sumOfDigits(int n) {
    // Write your code here
    if(n<10) return n;
    else {
        int x = n%10;
        return x + sumOfDigits(n/10);
    }
}

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}

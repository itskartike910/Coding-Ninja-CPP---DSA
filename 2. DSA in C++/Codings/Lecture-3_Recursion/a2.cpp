#include <iostream>
// #include "solution.h"
using namespace std;

int countZeros(int n) {
  // Write your code here
  if(n<10){
    if(n==0) return 1;
    else return 0;
  }
  int x=n%10,ans=0;
  if(x==0)
    ans = 1 ;
  return ans + countZeros(n/10);
}


int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}

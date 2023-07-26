#include<iostream>
// #include "Solution.h"
using namespace std;

int count(int n){
    //write your code here
    if(n==0) return 0;
    int digit = count(n/10);
    int ans = digit +1;
    return ans;
    }


int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}



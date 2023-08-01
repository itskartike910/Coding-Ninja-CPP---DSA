#include<iostream>
using namespace std;
// #include "Solution.h"

void print(int n){
    //write your code here
    if(n>=1){
        print(n-1);
        cout<<n<<" ";
    }
}


int main(){
    int n;
    cin >> n;
  
    print(n);
}



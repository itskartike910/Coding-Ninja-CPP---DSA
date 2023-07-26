// #include <bits/stdc++.h>
#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n==0){
        // cout<<n<<" ";
        return 0;
    }
    if(n==1){
        // cout<<n<<" ";
        return 1;
    }
    int a=fibonacci(n-1);
    int b=fibonacci(n-2);
    // cout<<n<<" ";
    return a+b;
}

int main(){
    int n;
    cin>>n;
    int fib =  fibonacci(n);
    cout<<fib<<endl;
}
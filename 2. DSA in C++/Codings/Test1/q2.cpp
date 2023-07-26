#include <iostream>
using namespace std;
// #include "solution.h"

#include <bits/stdc++.h>
int maximumProfit(int budget[], int n) {
    // Write your code here
    sort(budget,budget+n);
    int maxProfit = 0;

    // Calculate the maximum profit
    for (int i = 0; i < n; i++) {
        int currentProfit = budget[i] * (n - i);
        if (currentProfit > maxProfit) {
            maxProfit = currentProfit;
        }
    }
    return maxProfit;
}


int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}

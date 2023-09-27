#include <bits/stdc++.h>
using namespace std;
// #include "solution.h"

//Recursive method
//1
// int countMinStepsToOne(int n){
// 	//Write your code here
//     if(n==1) return 0;
//     int ans = 1 + countMinStepsToOne(n-1);
//     if(n%2==0) ans = min(ans,1+countMinStepsToOne(n/2));
//     if(n%3==0) ans = min(ans,1+countMinStepsToOne(n/3));
//     return ans;
// }

//2
// int countMinStepsToOne(int n){
// 	//Write your code here
//     if(n==1) return 0;
//     int x = countMinStepsToOne(n-1);
//     int y = INT_MAX, z = INT_MAX;
//     if(n%2==0) y=countMinStepsToOne(n/2);
//     if(n%3==0) z=countMinStepsToOne(n/3);
//     int ans = min(x,min(y,z))+1;
//     return ans;
// }

//Dynamic Programming
int countStepsToOne(int n){
	//Write your code here
    if(n<=1) return 0;
	vector<int> dp(n+1,0);
    dp[1] = 0;
    for(int i=2;i<n+1;i++){
        dp[i] = 1 + dp[i-1];
        if(i%2==0) dp[i] = min(dp[i],1+dp[i/2]);
        if(i%3==0) dp[i] = min(dp[i],1+dp[i/3]);
    }
    return dp[n];
}

//Memoization
int countMinStepsToOneHelper(int n,vector<int> &vec){
	//Write your code here
    if(n==1) return 0;
    if(vec[n]!=-1) return vec[n];
    int ans = 1 + countMinStepsToOneHelper(n-1,vec);
    if(n%2==0) ans = min(ans,1+countMinStepsToOneHelper(n/2,vec));
    if(n%3==0) ans = min(ans,1+countMinStepsToOneHelper(n/3,vec));
    vec[n]=ans;
    return ans;
}
int countMinStepsToOne(int n){
	//Write your code here
    vector<int> vec(n+1,-1);
    return countMinStepsToOneHelper(n,vec);
}

int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
	// cout << countStepsToOne(n);
}
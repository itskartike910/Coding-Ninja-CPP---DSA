#include <bits/stdc++.h>
using namespace std;

// #include "solution.h"


//Recursive Approach
// int minCostPath(int **input, int m, int n, int i=0 , int j=0 , int ans=0){
// 	//Write your code here
// 	if(i > m-1 or j > n-1)return INT_MAX;
//     if(i==m-1 && j==n-1){
// 		return ans + input[i][j];
// 	}
// 	int x = minCostPath(input,m,n,i+1,j,ans);
// 	int z = minCostPath(input,m,n,i,j+1,ans);
// 	int y = minCostPath(input,m,n,i+1,j+1,ans);
// 	ans = input[i][j] + min(x,min(y,z));
// 	return ans;
// }


//Memoization Approach
// int solve(int **input, int m, int n, int i , int j , int ans,vector<vector<int>> vec){
// 	if(i > m-1 or j > n-1)return INT_MAX;
//     if(i==m-1 && j==n-1){
// 		return vec[i][j] = ans + input[i][j];
// 	}
// 	if(vec[i][j]!=-1) return vec[i][j];
// 	int x = solve(input,m,n,i+1,j,ans,vec);
// 	int z = solve(input,m,n,i,j+1,ans,vec);
// 	int y = solve(input,m,n,i+1,j+1,ans,vec);
// 	ans = input[i][j] + min(x,min(y,z));
// 	return vec[i][j] = ans;
// }
// int minCostPath(int **input, int m, int n){
// 	//Write your code here
// 	vector< vector<int>> memo(m,vector<int>(n,-1));
// 	int i=0,j=0,ans=0;
// 	return solve(input,m,n,i,j,ans,memo);
// }


//Dynamic Programming Approach
int minCostPath(int **input, int m, int n){
    vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
    dp[m-1][n-1] = input[m-1][n-1];
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==m-1 && j==n-1){
                continue;
            }
            if(i==m-1){
                dp[i][j] = dp[i][j+1] + input[i][j];
            }
            else if(j==n-1){
                dp[i][j] = dp[i+1][j] + input[i][j];
            }
            else{
                dp[i][j] = min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]}) + input[i][j];
            }
        }
    }
    return dp[0][0];
}


int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	int ans =0 ;
	cout << minCostPath(arr, n, m) << endl;
}
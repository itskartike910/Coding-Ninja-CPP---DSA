// #include<bits/stdc++.h>
// using namespace std;


// int staircase(int n){
//     vector<int> dp(n+1,0);
//     int mod=1e9 + 7;
//     dp[0]=0;
//     dp[1]=1;
//     dp[2]=2;
//     for(int i=3;i<=n;i++){
//         dp[i] = (dp[i-1]%mod + dp[i-2]%mod + dp[i-3]%mod)%mod;
//     }
//     int ans = dp[n]%mod;
//     return ans;
// }


// int main(){
//     // take input from the user.
//     int t;
//     cin>>t;
//     int mod=1e9 + 7;
//     while(t--){
//         int n;
//         cin>>n;
//         int ans = staircase(n);
//         cout<<ans<<endl;
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
typedef long long int ll;
const ll m = 1e9 + 7;

int modAdd(ll a, ll b) {
  return (int)((a % m + b % m) % m);
}

int main() 
{
    int t;
    cin>>t;
    while(t--) {
      int n;
      cin>>n;
      
      int *arr = new int[n + 1]{0};
      arr[0] = 1;
      arr[1] = 1;
      arr[2] = 2;
      for(int i = 3; i <= n; i++) {
        arr[i] = modAdd(arr[i - 1], modAdd(arr[i - 2], arr[i - 3]));
      }
      
      cout<<arr[n]<<endl;
      
      delete[] arr;
    }
    return 0;
}

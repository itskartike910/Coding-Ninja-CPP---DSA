#include <iostream>
using namespace std;

// #include "solution.h"

const int MOD = 1000000007;

// int balancedBTs(int h) {
//     if (h <= 1) {
//         return 1;
//     }

//     long long int x = balancedBTs(h - 1);
//     long long int y = balancedBTs(h - 2);

//     long long int res1 = (x * x) % MOD;
//     long long int res2 = (2 * x * y) % MOD;

//     return (res1 + res2) % MOD;
// }


int balancedBTs(int h) {
    long long int dp[h + 1];
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= h; i++) {
        dp[i] = (dp[i - 1] * dp[i - 1] + 2 * dp[i - 1] * dp[i - 2]) % MOD;
    }

    return dp[h];
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
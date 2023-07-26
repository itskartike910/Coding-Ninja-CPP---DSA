#include <bits/stdc++.h>
using namespace std;

long long customPow(int base, int exponent) {
    long long result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

string decToBin(long long dec) {
    string bin = "";
    while (dec > 0) {
        int remainder = dec % 2;
        bin = to_string(remainder) + bin;
        dec /= 2;
    }
    return bin;
}

int main() {
    long long dec;
    cin >> dec;
    string bin = decToBin(dec);
    if(dec!=0)
        cout  << bin << endl;
    else
        cout<<0<<endl;
}

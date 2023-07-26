#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--){
        int n, count;
        string str;

        cin >> n >> str;
        count = 0;
        for (int i = 0; i < n; i++){
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
                count = 0;
                continue;
            }
            else{
                count++;
                if (count == 4)
                    break;
            }
        }
        if (count < 4){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
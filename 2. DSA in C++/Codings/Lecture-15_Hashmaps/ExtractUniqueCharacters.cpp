#include <iostream>
#include <string>
using namespace std;

// #include "solution.h"

#include<unordered_map>
string uniqueChar(string str) {
	// Write your code here
    int n=str.size();
    unordered_map<char,int> mp;
    for(int i=0;i<n;i++){
        mp[str[i]]++; 
    }
    string ans="";
    for(int i=0;i<n;i++){
        if(mp[str[i]]>0){
            ans.push_back(str[i]);
            mp[str[i]]=0;
        }
    }
    return ans;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
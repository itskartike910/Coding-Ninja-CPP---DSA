#include<bits/stdc++.h>
using namespace std;



int main(){
    // write your code here
    vector<vector<char>> crossword(10,vector<char>(10));
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>crossword[i][j];
        }
    }
    string words;
    cin>>words;
    return 0;
}
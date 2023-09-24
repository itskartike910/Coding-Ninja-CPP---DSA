#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

// #include "solution.h"


bool check(int n,int row,int col,vector<vector<int>> &vec){
    //Checking vertically up
    for(int i=row-1;i>=0;i--){
        if(vec[i][col]==1) return false;
    }
    //Checking left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if (vec[i][j] == 1 ) return false;
    }
    //Checking Right diagonal
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if (vec[i][j] == 1 ) return false;
    }
    return true;
}

void nQueensHelper(int n,vector<vector<int>> &vec,int row,vector<vector<int>> &sol){
    if(row==n){ 
        vector<int> res;
        for(auto v:sol){
            for(int i:v){
                res.push_back(i);
            }
        }
        vec.push_back(res);
        return;
    }
    for(int i=0;i<n;i++){
        if(check(n,row,i,sol)){
            sol[row][i] = 1;
            nQueensHelper(n,vec,row+1,sol);
            sol[row][i] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n){
    // Write your code here.
    if(n==1) return {{1}};
    if(n==2 || n==3) return {};
    vector<vector<int>> solution(n,vector<int>(n,0));
    vector<vector<int>> ans;
    nQueensHelper(n,ans,0,solution);
    return ans;
}


class Runner
{
    int n;

public:
    
    void takeInput()
    {
        cin >> n;
    }
    void execute()
    {
        auto ans = nQueens(n);
    }
    void executeAndPrintOutput()
    {
        auto ans = nQueens(n);
        if(ans.size())
        {
            sort(ans.begin(),ans.end());
            for(auto v:ans)
            {
                for(auto i:v)cout << i << " ";
                cout << endl;
            }
        }
        else cout << "\'No Configuration\'";
    }
};

int main()
{
        Runner runner;
        runner.takeInput();
        runner.executeAndPrintOutput();   
    return 0;
    
}
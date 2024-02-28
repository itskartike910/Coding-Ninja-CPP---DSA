#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> prereq;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        prereq.push_back({a,b});
    }
    vector<bool> visited(n, false);
    Solution obj;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            if(obj.canFinish(n, prereq)) cout<<"true"<<endl;
            else cout<<"false"<<endl;
        }
    }
    return 0;

}
//UNDIRECTED GRAPH
class Solution {
    bool isCycleBFS(int n, vector<vector<int>> &mat, vector<bool> &visited ){
        if(n==0 || n==1) return true;
        queue<pair<int,int>> q; //Current node val and parent node val;
        q.push({0,-1});
        visited[0] = true;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it:mat[node]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push({it,node});
                }
                else if(visited[it] && parent != it){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleDFS(int st, int par, vector<vector<int>> &mat, vector<bool> &visited){
        visited[st] = true;
        for(auto it:mat[st]){
            if(!visited[st]){
                if(isCycleDFS(it, st, mat, visited)) return true;
            }
            else if(it != par){
                return true;
            }
        }
        return false;
    }
public:
    //Simply we have to check if there is any cycle in the given graph or not;
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                // if(isCycleBFS(n, prereq, visited)) return false;
                if(isCycleDFS(0, -1, prereq, visited)) return false;
            }
        }
        return true;
    }
};
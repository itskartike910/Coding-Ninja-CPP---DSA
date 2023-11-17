#include <bits/stdc++.h>
using namespace std;

bool getPathDFS(vector<int> &ans,int s, int d,vector<vector<int>> graph,int n,vector<bool> &visited){
    if(s==d){
        ans.push_back(s);
        return true;
    }
    visited[s] = true;
    for(int i=0;i<n;i++){
        if(graph[s][i]==1 && !visited[i]){
            if(getPathDFS(ans,i,d,graph,n,visited)){
                ans.push_back(s);
                return true;
            }
        }
    }
    return false;
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>> graph(v,vector<int>(v,0));
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    
    int s,d;
    cin>>s>>d;
    vector<int> ans;
    vector<bool> visited(v,false);
    if(getPathDFS(ans,s,d,graph,v,visited)){
        // reverse(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}

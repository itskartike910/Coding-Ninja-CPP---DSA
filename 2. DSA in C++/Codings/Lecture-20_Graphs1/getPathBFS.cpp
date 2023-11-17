#include <bits/stdc++.h>
using namespace std;

bool getPathBFS(vector<int> &ans,int s, int d,vector<vector<int>> graph){
    if(graph[s][d]==1){
        ans.push_back(s);
        return true;
    }
    int n = graph.size();
    vector<bool> visited(n,false);
    vector<int> parent(n, -1);
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(t==d) break;
        for (int i=0;i<n;i++){
            if(graph[t][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;
                parent[i]=t;
            }
        }
    }
    if(!visited[d]){
        return false;
    }
    for(int v=d;v!=-1;v=parent[v]){
        ans.push_back(v);
    }
    return true;
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
    if(getPathBFS(ans,s,d,graph)){
        // reverse(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}

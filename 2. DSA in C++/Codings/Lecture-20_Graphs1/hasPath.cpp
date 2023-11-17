#include <bits/stdc++.h>
using namespace std;

//Using BFS
bool hasPath(vector<vector<int>> graph,int s,int e){
    if(graph[s][e]==1) return true;
    int n = graph.size();
    queue<int> q;
    vector<bool> visited(n,false);
    q.push(s);
    visited[s]=true;
    while (!q.empty()){
        int t  = q.front();
        q.pop();
        for (int i=0 ;i<n;i++){
            if(graph[t][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;
                if(i==e || graph[i][e]==1) return true;
            }
        }
    }
    return false;
}

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    vector<vector<int>> graph(v,vector<int>(v,0));
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    int start,end;
    cin>>start>>end;
    cout<<((hasPath(graph,start,end)==1) ? "true" : "false" )<<endl;
    return 0;
}
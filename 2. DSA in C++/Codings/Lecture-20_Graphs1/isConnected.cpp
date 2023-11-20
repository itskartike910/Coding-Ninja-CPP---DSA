#include <bits/stdc++.h>
using namespace std;

void BFStraversal(vector<vector<int>> graph,vector<int> &vec){
    if(graph.size()==0) return;
    queue<int> q;
    int n = graph.size();
    vector<bool> visited(n, false);
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int val = q.front();
        q.pop();
        // cout << val << " ";
        vec.push_back(val);
        // visited[val]=true;
        for(int i=0;i<n;i++){
            if(i==val){
                continue;
            }
            if(graph[val][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
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
    vector<int> vec;
    BFStraversal(graph,vec);
    sort(vec.begin(),vec.end());
    bool ans = true;
    for(int i=0;i<v;i++){
        if(i!=vec[i]){
            ans = false;
            break;
        }
    }
    cout<<(ans ? "true" : "false" )<<endl;
    return 0;
}
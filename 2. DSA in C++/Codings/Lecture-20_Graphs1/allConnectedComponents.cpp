#include <bits/stdc++.h>
using namespace std;

void printComp(vector<vector<int>> graph,vector<bool> &visited,int s,int n, vector<int> &comp){
    comp.push_back(s);
    visited[s] = true;
    for (int i = 0; i < n; i++){
        if (i == s){
            continue;
        }
        if (graph[s][i] == 1){
            if (visited[i]){
                continue;
            }
            visited[i]=true;
            printComp(graph, visited,i,n,comp);
        }
    }
}
void connectedComp(vector<vector<int>> graph){
    int n = graph.size();
    vector<bool> visited(n, false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int> comp;
            printComp(graph,visited,i,n,comp);
            sort(comp.begin(), comp.end());
            for(int j=0;j<comp.size();j++){
                cout<<comp[j]<<" ";
            }
            cout<<endl;
        }
    }
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
    connectedComp(graph);
    return 0;
}

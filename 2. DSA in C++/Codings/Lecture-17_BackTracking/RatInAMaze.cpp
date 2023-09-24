/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;


void ratInAMazeSolver(int n,vector<vector<int>> &grid,vector<vector<int>> &sol,int x,int y){
    if(x==n-1 && y==n-1){
        sol[x][y]=1;
        // printing the path
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<sol[i][j]<<" ";
            }
        }
        cout<<endl;
        sol[x][y]=0;    //can be or cannot be
        return;
    }

    if(x<0 ||x>=n || y<0 || y>=n || grid[x][y]==0 || sol[x][y]==1) return;

    sol[x][y]=1;

    ratInAMazeSolver(n,grid,sol,x-1,y);
    ratInAMazeSolver(n,grid,sol,x+1,y);
    ratInAMazeSolver(n,grid,sol,x,y-1);
    ratInAMazeSolver(n,grid,sol,x,y+1);

    sol[x][y]=0;

    return;
}

void ratInAMaze(int n,vector<vector<int>> &grid){
    vector<vector<int>> sol(n,vector<int> (n,0));
    ratInAMazeSolver(n,grid,sol,0,0);
    return;
}


int main() {
	// Write your code here
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    ratInAMaze(n,grid);
	return 0;
}

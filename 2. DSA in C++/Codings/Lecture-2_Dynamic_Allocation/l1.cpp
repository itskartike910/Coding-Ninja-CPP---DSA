//Dyanmic array allocation
#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    //creating a dyanmic array of size m*n;
    int **arr = new int * [m];
    for(int i = 0; i < m; i++){
        arr[i] = new int [n];
        for(int j=0;j<n;j++){
            //taking input;
            cin>>arr[i][j];
        }
    }

    //deleting the dynamic array from the heap;
    for(int i=0;i<m;i++){
        delete [] arr[i];
    }
    delete []arr;
}
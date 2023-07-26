#include <iostream>
using namespace std;
// #include "solution.h"
void print2DArray(int input[][1000], int row, int col) {
	// Write your code here
    for(int i=0;i<row;i++){
        for(int k=row;k>i;k--){
            for(int j=0;j<col;j++){
                cout<<input[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
int main() {
    int row, col;
    cin >> row >> col;

    int input[row][1000];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>input[i][j];
        }
    }
    print2DArray(input, row, col);
}

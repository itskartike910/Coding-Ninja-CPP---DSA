#include <iostream>
using namespace std;

// #include "solution.h"
void wavePrint(int **input, int rows, int cols)
{
    //Write your code here
    int *arr=new int[rows*cols],k=0;
    for(int j=0;j<cols;j++){
        if(j%2==0){
            for(int i=0;i<rows;i++,k++){
                arr[k]=input[i][j];
            }
        }
        else{
            for(int i=rows-1;i>=0;i--,k++){
                arr[k]=input[i][j];
            }
        }
    }
    for (int i = 0; i < rows*cols; i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int row, col;
		cin >> row >> col;
		int **input = new int *[row];
		for (int i = 0; i < row; i++)
		{
			input[i] = new int[col];
			for (int j = 0; j < col; j++)
			{
				cin >> input[i][j];
			}
		}
		wavePrint(input, row, col);
		cout << endl;
	}
}
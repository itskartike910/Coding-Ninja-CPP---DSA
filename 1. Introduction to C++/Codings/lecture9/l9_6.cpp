//Rotate Array

#include <iostream>
using namespace std;

// #include "solution.h"
// void swap(int *arr, int i, int j){
//     int temp = arr[i];
//     arr[i]=arr[j];
//     arr[j]=temp;
// }

// void leftShiftByOne(int *arr,int n){
//     int temp=arr[0];
//     for(int i=0;i<n-1;i++){
//         arr[i]=arr[i+1];
//     }
//     arr[n-1]=temp;
// }

void rotate(int *input, int d, int n)
{
    //Write your code here
    int arr[d];
    for(int i=0;i<d;i++){
        arr[i]=input[i];
    }
    for(int i=0;i<n-d;i++){
        input[i]=input[i+d];
    }
    for(int i=n-d;i<n;i++){
        input[i]=arr[i-n+d];
    }
    
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}
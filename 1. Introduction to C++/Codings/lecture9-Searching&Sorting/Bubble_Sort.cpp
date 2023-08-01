//Bubble Sort

#include <iostream>
using namespace std;

// #include "solution.h"
void swap(int *arr , int a , int b){
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void bubbleSort(int *arr, int n)
{
    //Write your code here
    int flag,a=n;
	while(--n){
		flag=0;
		for(int i=0;i<n;i++){
			if(arr[i]>arr[i+1]){
				flag=1;
				swap(arr,i,i+1);
			}
		}
		if(flag==0){
			break;
		}
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

		bubbleSort(input, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		delete[] input;
		cout << endl;
	}
}
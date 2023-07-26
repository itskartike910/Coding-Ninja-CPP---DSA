//Insertion Sort
#include <iostream>
using namespace std;

// #include "solution.h"
void insertionSort(int *arr, int n)
{
    //Write your code here
    int temp,j;
	for(int i=1;i<n;i++){
		temp = arr[i];
		for(j=i-1 ; j>=0 && arr[j]>temp ; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = temp;
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

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		insertionSort(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		delete[] input;
		cout << endl;
	}

	return 0;
}
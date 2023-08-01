#include <iostream>
using namespace std;

// #include "solution.h"
// You have been given a random integer array/list(ARR) of size N. You have been required to push all the zeros that are present in the array/list to the end of it. Also, make sure to maintain the relative order of the non-zero elements.

void swap(int *arr,int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void pushZeroesEnd(int *input, int size)
{
    //Write your code here
    for(int i=0,j=i+1;i<size && j<size;){
        if(input[i]==0){
            if(input[j]!=0){
                swap(input, j, i);
            }
            j++;
        }
        else if(input[i]!=0){
            i++;
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

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		pushZeroesEnd(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}
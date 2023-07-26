#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

// #include "solution.h"
void swap(int arr[],int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
int findZero(int arr[],int s,int n){
    for(int i=s;i<n;i++) if(arr[i]==0) return i;
}

void sortZeroesAndOne(int *input, int size)
{
    //Write your code here
    if(input[0]!=0){
        swap(input,0,findZero(input, 0, size));
    }
    else{
        for(int i=1;i<size;i++){
            int a=input[i];
            if(a!=0)
                for (int j = i + 1; j < size; j++) {
                    if (input[j]!=0) swap(input,j,findZero(input, j+1, size));
                }
        }
    }
	return ;
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

		sortZeroesAndOne(input, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}
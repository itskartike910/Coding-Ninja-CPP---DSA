#include <iostream>
using namespace std;

// #include "solution.h"

#include<bits/stdc++.h>
int findDuplicate(int *arr, int n)
{
    //Write your code here
    sort(arr,arr+n);
    for(int i=1;i<=n-1;i++){
        if(arr[i]==arr[i+1]){
            return arr[i];
        }
    }
    return arr[n-1];
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

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}
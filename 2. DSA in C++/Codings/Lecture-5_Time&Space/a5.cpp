#include <iostream>
#include <algorithm>
using namespace std;

// #include "solution.h"
#include<bits/stdc++.h>


int tripletSum(int *arr, int n, int num){
	//Write your code here


    //int count = 0;  
    // for(int i=0;i<n-2;i++){
	// 	if(arr[i]<=num)
	// 		for(int j=i+1;j<n-1;j++){
	// 			if(arr[j]<=num)
	// 				for(int k = j+1;k<n;k++){
	// 					if(arr[i]+arr[j]+arr[k]==num) count++;
	// 				}
	// 		}
    // }
    // return count;


    // int count = 0;
    // sort(arr, arr + n);
    // for (int i = 0; arr[i] <= num && i < n - 2; i++){
    //     for (int j = i + 1; arr[j] <= num && j < n - 1; j++){
    //         for (int k = j + 1; k < n; k++){
    //             if (arr[i] + arr[j] + arr[k] == num)
    //                 count++;
    //         }
    //     }
    // }
    // return count;
    

	int count=0;
	sort(arr,arr+n);
	for(int i=0;i<n-2;i++){
		int temp = num - arr[i];
		int j=i+1;
		int k=n-1;
		while(j<k){
			int sum = arr[j]+arr[k];
			if(sum<temp){
				j++;
			}
			else if(sum>temp){
				k--;
			}
			else{
				count++;
				// j++;
				k--;
			}
		}
	}
	return count;


	// int count=0;
	// sort(arr,arr+n);
	// for(int k=0,i=k+1 ; i<n-2 && k<n-3 ; i++){
	// 	int temp = num - arr[k];
	// 	for(int j=i+1 ; j<n ; j++){
	// 		if(arr[i]+arr[j]==temp){
	// 			count++;
	// 		}
	// 	}
	// 	if(i==n-3){
	// 		k++;
	// 		i=k+1;
	// 	}
	// }
	// return count;
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int size;
		int x;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;
		cout << tripletSum(input, size, x) << endl;
		delete[] input;
	}
	return 0;
}
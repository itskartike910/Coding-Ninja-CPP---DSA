#include <iostream>
using namespace std;

// #include "solution.h"

#include <bits/stdc++.h>
void rotate(int *input, int d, int n){
    //Write your code here
	// if(n!=0)
	// d=d%n;
	// while(d--){
	// 	int temp = input[0];
	// 	for(int i=0;i<n;i++){
	// 		input[i] = input[i+1];
	// 	}
	// 	input[n-1]=temp;
	// }
	reverse(input,input+n);
	reverse(input,input+n-d);
	reverse(input+n-d,input+n);
}

int main(){
	int t;
	cin >> t;
	
	while (t--){
		int size;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; ++i){
			cin >> input[i];
		}
		int d;
		cin >> d;
		rotate(input, d, size);
		for (int i = 0; i < size; ++i){
			cout << input[i] << " ";
		}
		delete[] input;
		cout << endl;
	}
	return 0;
}
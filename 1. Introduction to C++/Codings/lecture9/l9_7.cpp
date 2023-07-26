//Second Largest in array

#include <iostream>
using namespace std;

// #include "solution.h"
int findSecondLargest(int *input, int n)
{
    //Write your code here
    int max=input[0],smax=-2147483648,flag=0;
    for(int i=0;i<n;i++){
        if(input[i]>=max){
            // smax=max;
            // flag=1;
            max=input[i];
        }
    }
    for(int i=0;i<n;i++){
        if (input[i] >= smax && input[i] < max) {
            smax = input[i];
        }
    }
    return smax;
    // if(flag==1) return smax;
    // else return -2147483648;
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

		cout << findSecondLargest(input, size) << endl;

		delete[] input;
	}

	return 0;
}
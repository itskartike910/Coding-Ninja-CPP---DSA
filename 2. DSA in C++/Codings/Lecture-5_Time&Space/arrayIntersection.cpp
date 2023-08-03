#include <iostream>
#include <algorithm>
using namespace std;

// #include "solution.h"

void intersection(int *arr1, int *arr2, int n, int m) {
    //Write your code here
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + m);
	// for(int i=0;i<n;i++){
	// 	for(int j=i;arr1[i]>=arr2[j];j++){
	// 		if(arr1[i]==arr2[j]){
	// 			cout<<arr2[j]<<" ";
	// 			break;
	// 		}
	// 	}
	// }	
	int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr1[i] > arr2[j]) {
            j++;
        }
        else if (arr2[j] > arr1[i]) {
            i++;
        }
        else {
 
            // when both are equal
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}
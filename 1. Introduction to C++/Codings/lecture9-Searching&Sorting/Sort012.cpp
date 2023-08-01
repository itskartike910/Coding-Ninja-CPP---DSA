//Sort 0,1,2s
#include <iostream>
#include <algorithm>
using namespace std;

// #include "solution.h"
void swap(int *arr,int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void sort012(int *arr, int n)
{
    //Write your code here
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr,low++,mid++);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr,mid, high--);
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
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		delete[] arr;
		cout << endl;
	}

	return 0;
}
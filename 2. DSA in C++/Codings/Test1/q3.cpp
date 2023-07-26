#include <iostream>
// #include "solution.h"
using namespace std;

bool isPossible(int *input, int size, int index, int sum5, int sum3) {
    if (index == size) {
        return sum5 == sum3;
    }
    if (input[index] % 5 == 0) {
        return isPossible(input, size, index + 1, sum5 + input[index], sum3);
    } else if (input[index] % 3 == 0) {
        return isPossible(input, size, index + 1, sum5, sum3 + input[index]);
    } else {
        return isPossible(input, size, index + 1, sum5 + input[index], sum3) ||
               isPossible(input, size, index + 1, sum5, sum3 + input[index]);
    }
}

bool splitArray(int *input, int size) {
    return isPossible(input, size, 0, 0, 0);
}



int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}

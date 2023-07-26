#include<iostream>
using namespace std;
// #include "solution.h"

bool checksequenece(char large[], char* small) {
    // Base cases
    if (*small == '\0') {
        // Reached the end of small, all characters found in order
        return true;
    }
    if (*large == '\0') {
        // Reached the end of large, not all characters found in order
        return false;
    }

    // Recursive case
    if (*large == *small) {
        // Current characters match, check the remaining characters
        return checksequenece(large + 1, small + 1);
    } else {
        // Current characters don't match, check the next character in large
        return checksequenece(large + 1, small);
    }
}


int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}

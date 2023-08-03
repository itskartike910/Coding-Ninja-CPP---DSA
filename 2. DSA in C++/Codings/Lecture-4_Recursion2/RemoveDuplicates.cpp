#include <iostream>
using namespace std;
// #include "solution.h"

#include <bits/stdc++.h>
void leftShiftbyOne(char arr[],int startIdx){
    int n = strlen(arr);
    for(int i=startIdx;i<n;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]='\0';
}


void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
    if(input[0]=='\0') return;
    if(input[0]==input[1]){
        leftShiftbyOne(input,1);
        removeConsecutiveDuplicates(input);
    }
    else{
        removeConsecutiveDuplicates(input+1);
    }

}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
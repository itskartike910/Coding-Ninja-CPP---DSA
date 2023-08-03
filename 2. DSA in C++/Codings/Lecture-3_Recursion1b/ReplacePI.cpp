#include <iostream>
#include <bits/stdc++.h>
// #include "solution.h"
using namespace std;
// Change in the given string itself. So no need to return or print anything

void replacePi(char input[], int start = 0) {
    // Base case: If the string is empty or start index exceeds the length, return
    if (input[start] == '\0' || input[start + 1] == '\0') {
        return;
    }

    // If the current two characters are 'p' and 'i'
    if (input[start] == 'p' && input[start + 1] == 'i') {
        // Shift the string to the right by 2 positions to make space for "3.14"
        int length = strlen(input);
        for (int i = length; i >= start + 2; i--) {
            input[i + 2] = input[i];
        }

        // Replace "pi" with "3.14"
        input[start] = '3';
        input[start + 1] = '.';
        input[start + 2] = '1';
        input[start + 3] = '4';

        // Recursive call for the remaining string
        replacePi(input, start + 4);
    } else {
        // Recursive call for the remaining string
        replacePi(input, start + 1);
    }
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}



// #include <iostream>
// #include <bits/stdc++.h>
// // #include "solution.h"
// using namespace std;

// void rightShiftFromIndex(char arr[], int startIdx) {
//     int n = strlen(arr);
//     for (int i = n - 1; i > startIdx; --i)
//         arr[i] = arr[i - 1];
//     arr[n]='\0';
// }
// // Change in the given string itself. So no need to return or print anything

// void replacePi(char input[]) {
// 	// Write your code here
// 	int n=strlen(input);
// 	int i=0;
//     while(i<n){
//         if(input[i]=='p' && input[i+1]=='i'){
//             input[i]='3';
//             input[i+1]='.';
//             rightShiftFromIndex(input,i+2);
//             input[i+2]='1';
//             n++;
//             rightShiftFromIndex(input,i+3);
//             input[i+3]='4';
//             n++;
//             i+=3;
//         }
//         else
//             i++;
//     }
// }

// int main() {
//     char input[10000];
//     cin.getline(input, 10000);
//     replacePi(input);
//     cout << input << endl;
// }

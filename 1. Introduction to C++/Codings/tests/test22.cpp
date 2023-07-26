#include<iostream>
#include<bits/stdc++.h>
// #include "solution.h"
using namespace std;
/* input - Input String
*  output - Save the result in the output array (passed as argument). You don’t have to 
*  print or return the result
*/
void minLengthWord(char input[], char output[]){
	// Write your code here	
    // int n = strlen(input);
    // int length=0,j=0,s=0,min=INT_MAX;
    // while(j<n){
    //     if((input[j]==' ' || input[j]=='\0') && min>length){
    //         int i=0;
    //         for(;s<j;s++){
    //             output[i++]=input[s];
    //         }
    //         output[i]='\0';
    //         min = length;
    //         length = 0;
    //         s=j+1;
    //         j++;
    //     }
    //     else{
    //         length++;
    //         j++;
    //     }
    // }
    int inputLength = strlen(input);
    std::string word;
    std::string minWord;
    int minWordLength = INT_MAX;

    int start = 0;
    for (int i = 0; i <= inputLength; ++i) {
        if (input[i] == ' ' || input[i] == '\0') {
            word = std::string(input + start, i - start);
            int wordLength = word.length();
            if (wordLength < minWordLength) {
                minWord = word;
                minWordLength = wordLength;
            }
            start = i + 1;
        }
    }

    // Copy the characters of the minimum length word to the output array
    strcpy(output, minWord.c_str());
}

int main(){
  char ch[10000], output[10000];
  cin.getline(ch, 10000);
  minLengthWord(ch, output);
  cout << output << endl;
}

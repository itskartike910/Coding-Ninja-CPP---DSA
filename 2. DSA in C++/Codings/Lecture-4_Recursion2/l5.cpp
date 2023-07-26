#include <iostream>
#include <string>
// #include "solution.h"
using namespace std;

//wrong->using recursion

// int KeypadStrings(int num,string output[],int index,string str[],string currentStr,int count){
//     if(num==0){
//         output[index] = currentStr;
//         return count+1;
//     }
//     int lastDigit = num%10;
//     string letters = str[lastDigit];
//     count++;
//     for(char c : letters){
//         KeypadStrings(num/10,output,index+count,str,c+currentStr,count);
//     }
//     return count;
// }

// int keypad(int num, string output[]){
//     //             0  1   2     3     4     5     6      7     8      9
//     string str[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//     return KeypadStrings(num,output,0,str,"",0);
// }


//using iteration, recursion both
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string input;
    if(num == 0){
        output[0] = "";
        return 1;
    }
    int n = num%10;
    num = num/10;
    int smalloutputsize = keypad(num, output);
    switch(n){
        case 2: input = "abc";
            break;
        case 3: input = "def";
            break;
        case 4: input = "ghi";
            break;
        case 5: input = "jkl";
            break;
        case 6: input = "mno";
            break;
        case 7: input = "pqrs";
            break;
        case 8: input = "tuv";
            break;
        case 9: input = "wxyz";
            break;
    }
    int ans_size=smalloutputsize*(input.size());
    string temp[ans_size];
    int k=0;
    for(int i=0; i<smalloutputsize; i++){
        for(int j=0; j<input.size(); j++){
            temp[k] = output[i]+input[j];
            k++;
        }
    }
    for(int i=0; i<ans_size; i++){
        output[i] = temp[i];
    }
    return input.size()*smalloutputsize;
}


int main(){
    int num;
    cin >> num;
    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

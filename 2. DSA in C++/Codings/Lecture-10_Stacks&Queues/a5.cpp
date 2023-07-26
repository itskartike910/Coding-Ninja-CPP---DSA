#include <iostream>
#include <string>
using namespace std;


// #include <stack>
// int countBracketReversals(string input) {
// 	// Write your code here
//     stack<char> s;
// 	int count=0;
//     for(int i=0;i<input.length();i++){
//         if(input[i]=='{'){
//             s.push('{');
//         }
//         else{
//             if(!s.empty() && s.top()=='{'){
//                 s.pop();
//             }else {
//                 count++;
//             }
// 		}
//     }
//     int n=s.size()+count;
//     return ((n)%2==0) ? ((count==0) ? n/2 : n/2 +1) : -1;
// }

#include <stack>
int countBracketReversals(const std::string& input) {
    int n = input.length();
    if (n % 2 != 0) {
        return -1; // If the expression has an odd number of brackets, it can't be balanced.
    }

    int openingBrackets = 0;
    int closingBrackets = 0;

    for (char bracket : input) {
        if (bracket == '{') {
            openingBrackets++;
        } else {
            if (openingBrackets > 0) {
                openingBrackets--;
            } else {
                closingBrackets++;
            }
        }
    }

    // Calculate the number of reversals required
    int reversalsRequired = (openingBrackets + 1) / 2 + (closingBrackets + 1) / 2;
    return reversalsRequired;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}
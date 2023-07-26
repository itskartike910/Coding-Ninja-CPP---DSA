#include <iostream>
#include <string>
using namespace std;

// #include "solution.h"

#include<stack>
bool isBalanced(std::string expression) {
    stack<char> stack;
    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        } 
        else {
            if (stack.empty()) {
                return false; 
            }

            char top = stack.top();
            stack.pop();
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{') ) {
                return false; 
            }
        }
    }
    return stack.empty();
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}
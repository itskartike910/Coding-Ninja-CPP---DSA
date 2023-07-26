#include <iostream>
#include <string>
using namespace std;

// #include "solution.h"

#include <stack>
bool checkRedundantBrackets(string expression) {
    stack<char> st;
    for (char ch : expression) {
        if (ch == ')') {
            // Pop elements from the stack until an opening bracket is encountered
            char top = st.top();
            st.pop();
            bool isRedundant = true;
            while (top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedundant = false;
                }
                top = st.top();
                st.pop();
            }

            // If the sub-expression contains only operators, it has redundant brackets
            if (isRedundant) {
                return true;
            }
        } else {
            st.push(ch);
        }
    }

    return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}
#include <iostream>
#include <stack>
using namespace std;

// #include "solution.h"

#include <vector>
void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    vector<int> arr;
    for(int i=0;!input.empty();i++){
        arr.push_back(input.top());
        input.pop();
    }
    for(int i=0;i<arr.size();i++){
        input.push(arr[i]);
    }
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}
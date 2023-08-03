#include <iostream>
using namespace std;

// #include "solution.h"

#include<queue>
#include<stack>
void reverseQueue(queue<int> &input) {
	// Write your code here
    stack<int> s;
    while(!input.empty()){
        s.push(input.front());
        input.pop();
    }
    while (!s.empty()){
        input.push(s.top());
        s.pop();
    }
    
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}
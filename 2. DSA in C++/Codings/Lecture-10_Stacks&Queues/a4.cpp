
#include <iostream>
#include <stack>
using namespace std;

// #include "solution.h"'

#include <stack>

void calculateSpan(int prices[], int n, int spans[]) {
    std::stack<int> st;
    st.push(0); // Push the index of the first day into the stack
    spans[0] = 1; // The first day always has a span of 1

    for (int i = 1; i < n; i++) {
        // Pop the indices from the stack while the current price is greater than the price at the index in the stack
        while (!st.empty() && prices[i] > prices[st.top()]) {
            st.pop();
        }

        // If the stack is not empty, update the span for the current day
        spans[i] = (st.empty()) ? (i + 1) : (i - st.top());

        // Push the current index onto the stack
        st.push(i);
    }
}

int main() {
    int n;
    cin >> n;

    int* prices = new int[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int* spans = new int[n];
    calculateSpan(prices, n, spans);

    for (int i = 0; i < n; i++)
        cout << spans[i] << " ";

    delete[] prices;
    delete[] spans;

    return 0;
}
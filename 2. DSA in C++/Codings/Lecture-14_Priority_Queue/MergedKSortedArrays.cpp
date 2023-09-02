#include <iostream>
#include <vector>
using namespace std;

// #include "solution.h"

#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    priority_queue<int, vector<int> , greater<int>> pq;
    for(auto x:input){
        for(auto y:*x){
            pq.push(y);
        }
    }
    vector<int> vec;
    while(!pq.empty()){
        vec.push_back(pq.top());
        pq.pop();
    }
    return vec;
}

int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}
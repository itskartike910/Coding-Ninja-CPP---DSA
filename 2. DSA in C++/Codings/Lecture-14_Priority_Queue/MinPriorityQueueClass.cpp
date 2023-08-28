#include<bits/stdc++.h>
template<typename T>
class MinPriorityQueue{
    vector<int> vec;
    public:

    MinPriorityQueue(){
        //Default Constructor
    }

    bool isEmpty(){
        return (vec.size==0);
    }

    int getSize(){
        return vec.size;
    }

    int getMin(){
        if(isEmpty()) return INT_MIN;
        return vec[0];
    }
    
    void insert(int data){
        vec.push_back(data);
        int childIndex = vec.size - 1;
        while(childIndex>0){
            int parentIndex = (childIndex - 1)/2;
            if(vec[childIndex]<vec[parentIndex]){
                int temp = vec[parentIndex];
                vec[parentIndex] = vec[childIndex];
                vec[childIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin(){
        if(isEmpty()) return INT_MIN;
        if(vec.size()==1) {
            int ans = vec[0];
            vec.pop_back();
            return ans;
        }
        int ans = vec[0];
        vec[0] = vec[vec.size()-1];
        vec.pop_back();
        // Down Heapifying
        int PI = 0;
        while(true){
            int leftChildIndex = 2 * PI + 1;
            int rightChildIndex = 2 * PI + 2;
            int minIndex = PI;

            if (leftChildIndex < vec.size() && vec[leftChildIndex] < vec[minIndex]) {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < vec.size() && vec[rightChildIndex] < vec[minIndex]) {
                minIndex = rightChildIndex;
            }
            if (minIndex == PI) {
                break;
            } else {
                int temp = vec[PI];
                vec[PI] = vec[minIndex];
                vec[minIndex] = temp;
                PI = minIndex;
            }
        }
        return ans;
    }
    
};
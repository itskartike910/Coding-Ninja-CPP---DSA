#include<bits/stdc++.h>
template <typename T>
class MaxPriorityQueue {
    // Declare the data members here
    vector<int> vec;

    public:
    MaxPriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        vec.push_back(element);
        int childIndex = vec.size()-1;
        while(childIndex>0){
            int parentIndex = (childIndex-1)/2;
            if(vec[parentIndex]<vec[childIndex]){
                int temp = vec[parentIndex];
                vec[parentIndex] = vec[childIndex];
                vec[childIndex] = temp;
            }
            else{
                break;
            }
            childIndex=parentIndex;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty()) return INT_MIN;
        return vec[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty()) return INT_MIN;
        if(vec.size()==1){
            int ans = vec[0];
            vec.pop_back();
            return ans;
        }
        int ans = vec[0];
        vec[0] = vec[vec.size()-1];
        vec.pop_back();
        //Up Heapifying
        int PI = 0;
        while(PI<vec.size()){
            int LCI = 2*PI + 1;
            int RCI = 2*PI + 2;
            int maxInd = PI;
            if(LCI < vec.size() && vec[LCI]>vec[maxInd]){
                maxInd = LCI;
            }
            if(RCI < vec.size() && vec[RCI]>vec[maxInd]){
                maxInd = RCI;
            }
            if(maxInd == PI) break;
            else{
                int temp = vec[PI];
                vec[PI] = vec[maxInd];
                vec[maxInd] = temp;
                PI = maxInd;
            }
        }
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return vec.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return (vec.size()==0);
    }
};
#include <bits/stdc++.h>
using namespace std;

class DynamicArrays{
    int *data;
    int nextIdx;
    int capacity;

    public:

    DynamicArrays(){
        data = new int[2];
        nextIdx = 0;
        capacity = 2;
    }

    DynamicArrays(DynamicArrays const &d){
        //Shallow Copy
        // this->data = d.data;  

        //Deep Copy
        this->data = new int[d.capacity];
        for(int i=0;i<d.nextIdx;i++){
            this->data[i] = d.data[i];
        }
        this->nextIdx = d.nextIdx;
        this->capacity = d.capacity;
    }

    void push(int element){
        if(nextIdx==capacity){
            int *newdata = new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newdata[i] = data[i];
            }
            delete []data;
            data = newdata;
            capacity*=2;
        }
        data[nextIdx] = element;
        nextIdx++;
    }
    int get(int i){
        if(i<nextIdx){
            return data[i];
        }else{
            return -1;
        }
    }
    int size(){
        return nextIdx;
    }
    void print(){
        for(int i=0;i<nextIdx;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    DynamicArrays a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    
    a.print();

    return 0;
}
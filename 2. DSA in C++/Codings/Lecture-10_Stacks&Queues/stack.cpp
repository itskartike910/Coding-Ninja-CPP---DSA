#include<iostream>
using namespace std;

//Stacks using templates
template <typename T>
class Stack{
    T *arr;
    int top;
    int capacity;

    public:
    //constructor
    Stack(){
        // arr = new T[s];  //fixed size, bcz size is passed;
        top=0;
        capacity=1;     //Initial capacity, it doubles after full
        arr = new T[capacity];
    }

    //Is stack is empty?
    bool isEmpty(){
        return (top == 0);
    }

    //Using Dynamic Array , stack can never be full;

    // bool isFull(){
    //     return (top == capacity);
    // }

    //Fuction to push an element;
    void push(T n){
        if (top==capacity){
            T *newArr = new T[2*capacity];
            for(int i=0;i<capacity;i++){
                newArr[i]=arr[i];
            }
            delete[] arr;   //deleting old array 
            arr=newArr;      //assigning the pointer of newly created dynamic array
            capacity*=2;       //increasing its capacity by factor of two
            // cout<<"Stack is full. Unable to push."<<endl;
            // return;
        }
        arr[top++]=n;
    }
    

    //Function to pop an element;
    T pop(){
        if (isEmpty()){
            cout<<"Stack is empty. Unable to pop."<<endl;
            return -1;
        }
        return arr[--top];
    }

    //Returns number of elements and current size;
    int size(){
        return top;
    }

    //Returns capacity;
    T maxCapacity(){
        return capacity;
    }

    //Fuction to display like a stack
    void display(){
        for(int i=top-1 ;i>=0 ; --i) {
            cout<<"|  "<<arr[i]<<"  |"<<endl;
        }
        cout<<"+-----+"<<endl<<endl;
    }
};

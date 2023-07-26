#include <bits/stdc++.h>
using namespace std;

#include "stack.cpp"
#include "queue.cpp"

int main(){
    Stack<int> s;

    // cout<<"Stack is Empty? "<<s.isEmpty()<<endl;
    // // cout<<" . Stack is Full? "<<s.isFull()<<endl;
    // cout<<"Size of Stack is "<<s.size()<<endl;
    // cout<<"Maximum Capacity="<<s.maxCapacity()<<endl;
    // s.push(7);
    // s.display();
    // s.push(8);
    // s.display();
    // cout<<"Maximum Capacity="<<s.maxCapacity()<<endl;
    // s.push(5);
    // s.display();
    // s.push(6);
    // s.display();
    // cout<<"Maximum Capacity="<<s.maxCapacity()<<endl;
    // s.push(4);
    // s.display();
    // s.push(1);
    // s.display();
    // cout<<"Maximum Capacity="<<s.maxCapacity()<<endl;
    // int x=s.pop();
    // cout<<"Popped element is "<<x<<endl;
    // s.display();

    // cout<<"Stack is Empty? "<<s.isEmpty()<<endl;
    // // cout<<" . Stack is Full? "<<s.isFull()<<endl;
    // cout<<"Size of Stack is "<<s.size()<<endl;
    // return 0;

    QueueUsingArray<int> q(1);

    cout<<q.front()<<" "<<q.getSize()<<" "<<q.isEmpty()<<endl;
    q.display();
    q.enqueue(2);
    q.enqueue(6);
    q.enqueue(4);
    q.enqueue(9);
    q.display();
    cout<<q.front()<<" "<<q.getSize()<<" "<<q.isEmpty()<<endl;

    q.enqueue(7);
    q.dequeue();
    q.dequeue();
    q.display();
    cout<<q.front()<<" "<<q.getSize()<<" "<<q.isEmpty()<<endl;

    q.enqueue(3);
    q.display();
    cout<<q.front()<<" "<<q.getSize()<<" "<<q.isEmpty()<<endl;


}
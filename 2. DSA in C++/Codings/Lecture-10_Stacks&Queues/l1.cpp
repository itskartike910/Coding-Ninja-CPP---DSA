#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// #include "solution.h"

class Stack {
	// Define the data members
    Node *head;
    Node *tail;

    public:
    Stack() {
        // Implement the Constructor
        head=NULL;
        tail=NULL;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        if(tail==NULL) return 0;
        int count=1;
        Node *p=head;
        while(p!=tail){
            p=p->next;
            count++;
        }
        return count;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        if(!head && !tail) return true;   
        else return false;
    }

    void push(int element) {
        // Implement the push() function
        Node *node = new Node(element);
        if(head==NULL){
            head=node;
            tail=head;
        }
        else{
            tail->next=node;
            tail=tail->next;
        }
    }

    int pop() {
        // Implement the pop() function
        Node *p = head;
        if (head == NULL && tail == NULL) return -1;
        if (tail == head) {
            int x = tail->data;
            delete tail;
            head = NULL;
            tail = NULL; 
            return x;
        }
        while (p->next != tail) {
            p = p->next;
        }
        int x = tail->data;
        delete tail;
        tail = p;
        return x;
    }


    int top() {
        // Implement the top() function
        if(tail==NULL) return -1;
        return tail->data;
    }
};

int main() {
    Stack st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}
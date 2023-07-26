#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;
// #include "Solution.h"

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* nextNode = nullptr;

    while (curr) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

Node* NextLargeNumber(Node* head) {
    Node* rHead = reverseList(head);
    Node* curr = rHead;
    int carry = 1;

    while (curr) {
        int sum = curr->data + carry;
        carry = sum / 10;
        curr->data = sum % 10;
        curr = curr->next;
    }
    if (carry > 0) {
        Node* newcarry = new Node(carry);
        curr = rHead;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newcarry;
    }
    return reverseList(rHead);
}

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}




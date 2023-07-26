#include <iostream>

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;
// #include "solution.h"

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        // Store the next node
        next = current->next;

        // Reverse the current node's pointer
        current->next = prev;

        // Move the pointers one position ahead
        prev = current;
        current = next;
    }

    // Update the head to point to the new first node
    head = prev;

    return head;
}


Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        head = reverseLinkedList(head);
        print(head);
    }

    return 0;
}
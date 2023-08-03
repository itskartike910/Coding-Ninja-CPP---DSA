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


class Queue {
    // Define the data members
    Node* frontNode;
    Node* rearNode;
    int size;

   public:
    Queue() {
        // Initialize the data members
        frontNode = nullptr;
        rearNode = nullptr;
        size = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int data) {
        // Create a new node with the given data
        Node* newNode = new Node(data);

        if (isEmpty()) {
            // If the queue is empty, set both front and rear to the new node
            frontNode = newNode;
            rearNode = newNode;
        } else {
            // Update the rearNode's next pointer and move rearNode to the new node
            rearNode->next = newNode;
            rearNode = newNode;
        }

        size++; // Increment the size of the queue
    }

    int dequeue() {
        if (isEmpty()) {
            // Return some appropriate value to indicate an error or an empty queue condition
            return -1;
        }

        // Store the data of the front node
        int frontData = frontNode->data;

        // Move frontNode to the next node
        Node* temp = frontNode;
        frontNode = frontNode->next;

        // If frontNode becomes nullptr, the queue is empty, update rearNode accordingly
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        // Delete the previous front node and decrement the size of the queue
        delete temp;
        size--;

        return frontData;
    }

    int front() {
        if (isEmpty()) {
            // Return some appropriate value to indicate an error or an empty queue condition
            return -1;
        }

        // Return the data of the front node
        return frontNode->data;
    }
};



// #include "solution.h"

int main() {
    Queue q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}
//bubble sort iterative
#include <iostream>
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
// #include "solution.h"

Node* bubbleSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    bool swapped;
    Node* current;
    Node* prev;
    Node* temp = nullptr;

    do {
        swapped = false;
        current = head;
        prev = nullptr;

        while (current->next != temp) {
            if (current->data > current->next->data) {
                // Swap the nodes
                Node* nextNode = current->next;
                if (prev != nullptr) {
                    prev->next = nextNode;
                } else {
                    head = nextNode;
                }
                current->next = nextNode->next;
                nextNode->next = current;

                prev = nextNode;
                swapped = true;
            } else {
                prev = current;
                current = current->next;
            }
        }

        temp = current;

    } while (swapped);

    return head;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}
void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main()
{
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}
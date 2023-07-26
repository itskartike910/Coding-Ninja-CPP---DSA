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

Node* reverseLinkedList(Node* head, int k) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    int count = 0;

    while (current != nullptr && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != nullptr) {
        head->next = reverseLinkedList(next, k);
    }

    return prev;
}

Node* kReverse(Node* head, int k) {
    if (head == nullptr || k == 1 || k==0) {
        return head;
    }

    return reverseLinkedList(head, k);
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
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}
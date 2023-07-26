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

Node* merge(Node* list1, Node* list2) {
    // Base cases
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;

    Node* mergedList = nullptr;

    // Choose the smaller value as the new head
    if (list1->data <= list2->data) {
        mergedList = list1;
        mergedList->next = merge(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = merge(list1, list2->next);
    }

    return mergedList;
}

// Function to perform merge sort on a linked list
Node* mergeSort(Node* head) {
    // Base case: an empty list or a single node
    if (head == nullptr || head->next == nullptr)
        return head;

    // Find the middle of the list
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalf = slow->next;
    slow->next = nullptr;

    // Recursively sort the two halves
    Node* sortedFirstHalf = mergeSort(head);
    Node* sortedSecondHalf = mergeSort(secondHalf);

    // Merge the sorted halves
    return merge(sortedFirstHalf, sortedSecondHalf);
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
		head = mergeSort(head);
		print(head);
	}

	return 0;
}
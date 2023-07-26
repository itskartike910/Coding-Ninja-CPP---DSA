#include <iostream>
#include<stdio.h>


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

/*  
    Time Complexity : O(n)
    Space Complexity : O(n)
    where n is the size of singly linked list
*/

Node* InsertNode(Node* head, int pos, Node* newNode)
{
    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }
    if (head == NULL) {
        return head;
    }
    head->next = InsertNode(head->next, pos - 1, newNode);
    return head;
}



Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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
		int pos;
		cin >> pos;
        int val;
        cin>>val;
        Node* newNode = new Node(val);
		head = InsertNode(head, pos,newNode);
		print(head);
	}

	return 0;
}
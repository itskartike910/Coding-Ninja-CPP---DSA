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

int length(Node *head)
    {
        Node *temp = head;
        int count=0;
        while(temp->next != NULL){
            count++;
            temp = temp->next;
        }
        return count+1;
    }

Node *midPoint(Node *head){
    // Write your code here
    if(head==NULL) return head;
    int len = length(head);
    int mid = abs((len-1)/2);
    Node *p = head;
    for(int i=0;i<mid;i++){
        p=p->next;
    }
    return p;
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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		Node *mid = midPoint(head);
		if (mid != NULL)
		{
			cout << mid->data;
		}
		cout << endl;
	}
	return 0;
}
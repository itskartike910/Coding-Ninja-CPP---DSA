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


Node* swapNodes(Node* head, int i, int j) {
    if (i == j) {
        return head;
    }
    Node* prev1 = nullptr;
    Node* curr1 = head;
    int pos1 = 0;
    while (curr1 && pos1 < i) {
        prev1 = curr1;
        curr1 = curr1->next;
        pos1++;
    }
    Node* prev2 = nullptr;
    Node* curr2 = head;
    int pos2 = 0;
    while (curr2 && pos2 < j) {
        prev2 = curr2;
        curr2 = curr2->next;
        pos2++;
    }

    if (!curr1 || !curr2) {
        return head;
    }

    if (prev1) {
        prev1->next = curr2;
    } else {
        head = curr2;
    }

    if (prev2) {
        prev2->next = curr1;
    } else {
        head = curr1;
    }

    Node* temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;

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
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}
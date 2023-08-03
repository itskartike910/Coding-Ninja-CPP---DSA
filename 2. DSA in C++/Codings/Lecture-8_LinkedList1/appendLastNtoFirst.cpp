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

int length(Node *head) {
	if(head==NULL){
		return 0;
	}
	if(head->next==NULL){
		return 1;
	}
	int ans = 1 + length(head->next);
	return ans;
}

Node *appendLastNToFirst(Node *head, int n){
    //Write your code here
    if(n==0) return head;
    if(head == NULL || head->next==NULL) return head;
	Node *p=head;
    int len = length(head);
    // cout<<len<<endl;
    if(n<len)
        n = len - n;
    else
        n = n - len;
    Node *tail = head;
    while(tail->next != NULL){
        tail = tail->next ;
    }
    // cout<<tail->data<<endl;
    // cout<<n<<endl;
    if(n>=0){
        for(int i=1;i<n && p->next!=NULL;i++){
            p = p -> next;
        }
        tail->next = head;
        tail = p;
        head = p->next;
        p->next = NULL;
    }
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
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}
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

Node *skipMdeleteN(Node *head, int M, int N){
	// Write your code here
	if(head==NULL) return head;
	if(M==0 && N!=0){ 
        head=NULL;
        return head;
    }
    if(N==0 || (N==0 && M==0)){
        return head;
    }
    Node *p=head,*q=head;
    while(q->next!=NULL && p->next!=NULL){
        int flag=0;
        for(int i=1;i<M;i++){
            if(p->next!=NULL){
                p=p->next;
            }
            else{
                flag=1;
            }
        }
        q=p->next;
        if(flag==0){
            for(int i=1;i<=N;i++){
                if(q->next!=NULL){
                    q=q->next;
                }
                else{
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0){
			p->next = q;
			p=q;
        }
        else{
            p->next = q->next;
            p=q->next;
        }
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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}
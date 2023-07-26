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

#include <bits/stdc++.h>
bool isPalindrome(Node *head){
    //Write your code here
    Node *p = head;
    vector<int> arr;
    while(p!=NULL){
        arr.push_back(p->data);
        p = p->next;
    }
    int n=arr.size();
    int x = 0,y=n-1;
    while(x<=y){
        if(arr[x]!=arr[y]){
            return false;
        }
        x++,y--;
    }
    return true;
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
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}
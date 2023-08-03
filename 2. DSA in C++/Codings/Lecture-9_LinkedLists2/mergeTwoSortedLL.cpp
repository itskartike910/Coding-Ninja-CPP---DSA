#include <iostream>

class Node{
public:
	int data;
	Node *next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
// #include "solution.h"

// Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
//     //Write your code here
//     if(head1==NULL && head2==NULL) return head1;
//     if(head1!=NULL && head2==NULL )  {
//         return head1;
//     }
//     if(head1==NULL and head2!=NULL )  {
//         head1 = head2;
//         return head1;
//     }
//     Node *head=NULL,*tail=NULL;
//     if(head1->data < head2->data)
//         head=head1,tail=head1;
//     else head=head2,tail=head2;
//     while(head1!=NULL && head2!=NULL){
//         if(head1->data <= head2->data){
            
//         }
//     }
    
// }

//GPT's approach

Node* mergeTwoSortedLinkedLists(Node* head1, Node* head2) {
    // Check if either of the linked lists is empty
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }

    Node* mergedHead; // Pointer to the merged linked list head
    Node* current;    // Pointer to the current node in the merged list

    // Set the head of the merged list based on the smaller value in the heads of the input lists
    if (head1->data <= head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }

    // Set the current node to the merged list's head
    current = mergedHead;

    // Merge the two lists by comparing the values in each list
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    // If there are any remaining nodes in either list, append them to the merged list
    if (head1 != nullptr) {
        current->next = head1;
    }
    if (head2 != nullptr) {
        current->next = head2;
    }

    return mergedHead;
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
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}
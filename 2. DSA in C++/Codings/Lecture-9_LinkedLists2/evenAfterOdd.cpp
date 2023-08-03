#include <iostream>

class Node{
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

// Node *evenAfterOdd(Node *head){
// 	//write your code here
//     if((head->data)%2==0){
//         Node *p = head, *q = head,*k=head;
//         while(k->next!=NULL){
//             if(k->data%2!=0){
//                 head = k;
//                 break;
//             }
//             else{
//                 k=k->next;
//             }
//         }
//         Node * r = head->next;
//         while(q->next!=head){
//             q=q->next;
//         }
//         head->next=p;
//         q->next = r;
//     }
//     Node *p = head, *q = head;
//     while(((p->next)->data)%2!=0){
//         p = p->next;
//     }
//     q=(p->next);
//     for(Node *r=q;r->next!=NULL;){
//         if(((r->next)->data)%2!=0){
//             Node *temp = r->next;
//             r->next = temp->next;
//             p->next = temp;
//             temp->next = q;
//             p=p->next;
//         }
//         else{
//             r=r->next;
//         }
//     }

//     return head;
// }


Node* evenAfterOdd(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        // If the list is empty or contains only one element, no rearrangement needed
        return head;
    }

    Node* oddHead = nullptr;  // Head of the list containing odd numbers
    Node* oddTail = nullptr;  // Tail of the list containing odd numbers
    Node* evenHead = nullptr; // Head of the list containing even numbers
    Node* evenTail = nullptr; // Tail of the list containing even numbers

    Node* curr = head; // Current node being processed

    while (curr != nullptr) {
        if (curr->data % 2 != 0) {
            // Current node has an odd number
            if (oddHead == nullptr) {
                oddHead = curr;
                oddTail = curr;
            } else {
                oddTail->next = curr;
                oddTail = oddTail->next;
            }
        } else {
            // Current node has an even number
            if (evenHead == nullptr) {
                evenHead = curr;
                evenTail = curr;
            } else {
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
        }

        curr = curr->next;
    }

    if (oddHead == nullptr) {
        // If there are no odd numbers, return the list with even numbers only
        evenTail->next = nullptr;
        return evenHead;
    } else {
        oddTail->next = evenHead;
        if (evenTail != nullptr) {
            evenTail->next = nullptr;
        }
        return oddHead;
    }
}

Node *takeinput(){
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

void print(Node *head){
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}
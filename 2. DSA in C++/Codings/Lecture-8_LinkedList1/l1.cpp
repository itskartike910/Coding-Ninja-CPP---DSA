#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

// #include "solution.h"


class Runner
{
    int t;
    vector<int>X;
    vector<vector<int>> a;

    public:

    int length(Node *head)
    {
        //Write your code here
        Node *temp = head;
        int count=0;
        while(temp->next != NULL){
            count++;
            temp = temp->next;
        }
        return count+1;
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

    void execute(Node *head)
    {
        length(head);
    }

    void executeAndPrintOutput(Node *head)
    {
        cout << length(head) << endl;
    }
};



int main()
{
    Runner runner;
    Node *head = runner.takeinput();
    runner.executeAndPrintOutput(head);
}
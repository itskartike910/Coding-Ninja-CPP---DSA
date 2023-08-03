#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
// #include "solution.h"

/*
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<Node<int> *> vec;
    if(!root) return vec;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    vector<BinaryTreeNode<int> *> arr;
    while(!q.empty()){
        BinaryTreeNode<int> *t = q.front();
        q.pop();
        if (t == NULL) {
            if (q.empty()) {
                break;
            }
            // cout << endl;
            arr.push_back(NULL);
            q.push(NULL);
            continue;
        }
        // cout<<t->data<<" ";
        arr.push_back(t);
        if(t->left){
            q.push(t->left);
        }
        if(t->right){
            q.push(t->right);
        }
    }
    Node<int> * node = new Node<int>(arr[0]->data);
    vec.push_back(node);
    for(int i=1;i<arr.size();i++ ){
        if(arr[i]==NULL){
            int j=i+1;

        }
    }
}
*/

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    vector<Node<int>*> result;

    if (!root) {
        return result;
    }

    queue<BinaryTreeNode<int>*> queue;
    queue.push(root);

    while (!queue.empty()) {
        int level_size = queue.size();
        Node<int>* level_head = nullptr;
        Node<int>* prev_node = nullptr;

        for (int i = 0; i < level_size; i++) {
            BinaryTreeNode<int>* node = queue.front();
            queue.pop();

            Node<int>* list_node = new Node<int>(node->data);
            if (!level_head) {
                level_head = list_node;
            }
            if (prev_node) {
                prev_node->next = list_node;
            }
            prev_node = list_node;

            if (node->left) {
                queue.push(node->left);
            }
            if (node->right) {
                queue.push(node->right);
            }
        }
        result.push_back(level_head);
    }
    return result;
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}
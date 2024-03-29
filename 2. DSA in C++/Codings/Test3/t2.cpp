#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
// #include "solution.h"


vector<int>* longestPath(BinaryTreeNode<int>* root) {
    if (!root)
        return nullptr;
    
    vector<int>* leftPath = longestPath(root->left);
    vector<int>* rightPath = longestPath(root->right);
    
    if (!leftPath && !rightPath) {
        vector<int>* path = new vector<int>();
        path->push_back(root->data);
        return path;
    }
    
    if (leftPath && rightPath) {
        if (leftPath->size() > rightPath->size()) {
            leftPath->push_back(root->data);
            delete rightPath;
            return leftPath;
        } else {
            rightPath->push_back(root->data);
            delete leftPath;
            return rightPath;
        }
    }
    
    if (leftPath) {
        leftPath->push_back(root->data);
        return leftPath;
    } else {
        rightPath->push_back(root->data);
        return rightPath;
    }
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}

#include <iostream>
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

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;
// #include "solution.h"


void printNodesAtDistanceK(BinaryTreeNode<int> *root, int k) {
    // Base case: If the root is NULL, return.
    if (root == NULL) {
        return;
    }

    // If the current node is at distance K, print its data.
    if (k == 0) {
        cout << root->data << endl;
        return;
    }

    // Recur on the left and right subtrees with K-1 distance.
    printNodesAtDistanceK(root->left, k - 1);
    printNodesAtDistanceK(root->right, k - 1);
}

int nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Base case: If the root is NULL, return -1 (node not found).
    if (root == NULL) {
        return -1;
    }

    // If we've found the target node, print nodes at distance K from it.
    if (root->data == node) {
        printNodesAtDistanceK(root, k);
        return 0; // Indicate that we found the node at depth 0.
    }

    // Search for the target node in the left and right subtrees.
    int leftDistance = nodesAtDistanceK(root->left, node, k);

    // If the node was found in the left subtree, determine the distance to the target.
    if (leftDistance != -1) {
        if (leftDistance + 1 == k) {
            cout << root->data << " ";
        } else {
            printNodesAtDistanceK(root->right, k - leftDistance - 2);
        }
        return leftDistance + 1; // Increase the distance by 1.
    }

    int rightDistance = nodesAtDistanceK(root->right, node, k);

    // If the node was found in the right subtree, determine the distance to the target.
    if (rightDistance != -1) {
        if (rightDistance + 1 == k) {
            cout << root->data << " ";
        } else {
            printNodesAtDistanceK(root->left, k - rightDistance - 2);
        }
        return rightDistance + 1; // Increase the distance by 1.
    }

    // If the node was not found in either subtree, return -1.
    return -1;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
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
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
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
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
// #include "solution.h"

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    if(!root){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    // pair<int,int> leftSub = getMinAndMax(root->left);
    // pair<int,int> rightSub = getMinAndMax(root->right);

    // int lmin = leftSub.first;
    // int lmax = leftSub.second;
    // int rmin = rightSub.first;
    // int rmax = rightSub.second;

    // int minimum = min(lmin,rmin);
    // int maximum = max(lmax,rmax);

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    int maximum=INT_MIN,minimum=INT_MAX;

    while(!q.empty()){
        BinaryTreeNode<int> *t = q.front();
        q.pop();
        if(t->left){
            q.push(t->left);
            if(t->left->data < minimum)    minimum = t->left->data;
            if(t->left->data > maximum)    maximum = t->left->data;
        }
        if(t->right){
            q.push(t->right);
            if(t->right->data < minimum)    minimum = t->right->data;
            if(t->right->data > maximum)    maximum = t->right->data;
        }
    }

    if(root->data < minimum)    minimum = root->data;
    if(root->data > maximum)    maximum = root->data;
    pair<int,int> p;
    p.first = minimum;
    p.second = maximum;
    return p;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}
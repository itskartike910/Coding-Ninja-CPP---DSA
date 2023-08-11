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

#include<bits/stdc++.h>
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	queue<BinaryTreeNode<int> *> q;
    vector<int> vec;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> *t = q.front();
        q.pop();
        vec.push_back(t->data);
        if(t->left){
            q.push(t->left);
        }
        if(t->right){
            q.push(t->right);
        }
    }
    sort(vec.begin(), vec.end());
    int i=0,j=vec.size()-1;
    while(i<j){
        if(vec[i]+vec[j]==sum){
            cout<<vec[i]<<" "<<vec[j]<<endl;
            i++;j--;
        }
        else if(vec[i]+vec[j]>sum) j--;
        else i++;
    }
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
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}
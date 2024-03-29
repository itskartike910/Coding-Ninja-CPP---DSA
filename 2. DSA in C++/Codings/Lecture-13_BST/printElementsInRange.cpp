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
};

using namespace std;
// #include "solution.h"

// #include<vector>
// void inorderTraversal(BinaryTreeNode<int> *root,vector<int> &vec){
//     if(!root) return;
//     inorderTraversal(root->left,vec);
//     vec.push_back(root->data);
//     inorderTraversal(root->right,vec);
// }

// void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
// 	// Write your code here
//     if(!root) return ;
//     vector<int> vec;
//     inorderTraversal(root,vec);
//     for(int i=0;i<vec.size();i++){
//         if(vec[i]>=k1 && vec[i]<=k2){
//             cout<<vec[i]<<" ";
//         }
//     }
// }

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	// Write your code here
    if(!root) return;
    if(k1<=root->data){
        elementsInRangeK1K2(root->left,k1,k2);
    }
    if(root->data>=k1 && root->data<=k2) cout<<root->data<<" ";
    if(k2>=root->data){
        elementsInRangeK1K2(root->right,k1,k2);
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
    int k1, k2;
    cin >> k1 >> k2;
    elementsInRangeK1K2(root, k1, k2);
}
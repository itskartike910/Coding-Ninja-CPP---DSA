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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;
// #include "solution.h"

//------------//

#include <bits/stdc++.h>
struct SubtreeInfo {
    bool isBST;
    int size;
    int minValue;
    int maxValue;
};

SubtreeInfo largestBSTSubtreeHelper(BinaryTreeNode<int>* root) {
    if (!root) {
        return {true, 0, INT_MAX, INT_MIN};
    }

    SubtreeInfo leftInfo = largestBSTSubtreeHelper(root->left);
    SubtreeInfo rightInfo = largestBSTSubtreeHelper(root->right);

    if (leftInfo.isBST && rightInfo.isBST && root->data > leftInfo.maxValue && root->data < rightInfo.minValue) {
        int size = 1 + leftInfo.size + rightInfo.size;
        int minValue = std::min(root->data, leftInfo.minValue);
        int maxValue = std::max(root->data, rightInfo.maxValue);
        return {true, size, minValue, maxValue};
    }

    return {false, max(leftInfo.size, rightInfo.size), 0, 0};
}

bool isBST(BinaryTreeNode<int> *root, int minValue=INT_MIN, int maxValue=INT_MAX) {
    if (root == NULL) {
        return true;
    }
    int nodeValue = root->data;
    if (nodeValue <= minValue || nodeValue >= maxValue) {
        return false;
    }
    bool leftIsBST = isBST(root->left, minValue, nodeValue);
    bool rightIsBST = isBST(root->right, nodeValue, maxValue);

    return leftIsBST && rightIsBST;
}

int largestBSTSubtree(BinaryTreeNode<int>* root) {
	int x = largestBSTSubtreeHelper(root).size;
    return x;
}
//-----------//

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
    cout << largestBSTSubtree(root);
    delete root;
}
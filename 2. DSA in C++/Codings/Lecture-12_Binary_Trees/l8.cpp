#include <iostream>
#include <queue>

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
BinaryTreeNode<int>* buildTreeHelper(int *post,int *in,int inS, int inE, int postS, int postE){
    if(inE>inS || postS>postE) return NULL;
    int rootData = post[postE];
    int rIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i] == rootData){
            rIndex=i;
            break;
        }
    }
    //Left Subtree
    int lInS=inS;
    int lInE=rIndex-1;
    int lPostS=postS;
    int lPostE=lInE-lInS+lPostS;
    //Right Subtree
    int rInS=rIndex+1;
    int rInE=inE;
    int rPostS=lPostE+1;
    int rPostE=postE-1;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(post,in,lInS,lInE,lPostS,lPostE);
    root->right = buildTreeHelper(post,in,rInS,rInE,rPostS,rPostE);
    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    if(postLength!=inLength) return NULL;
    return buildTreeHelper(postorder,inorder,0,inLength-1,0,postLength-1);
}
*/

#include <unordered_map>

BinaryTreeNode<int>* buildTreeHelper(int *post, int *in, int inS, int inE, int postS, int postE, std::unordered_map<int, int>& indexMap) {
    if (inE < inS || postS > postE) return NULL;
    
    int rootData = post[postE];
    int rIndex = indexMap[rootData];
    
    // Left Subtree
    int lInS = inS;
    int lInE = rIndex - 1;
    int lPostS = postS;
    int lPostE = lInE - lInS + lPostS;
    
    // Right Subtree
    int rInS = rIndex + 1;
    int rInE = inE;
    int rPostS = lPostE + 1;
    int rPostE = postE - 1;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(post, in, lInS, lInE, lPostS, lPostE, indexMap);
    root->right = buildTreeHelper(post, in, rInS, rInE, rPostS, rPostE, indexMap);
    
    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    if (postLength != inLength) return NULL;
    
    // Create a hashmap to store indices of elements in the inorder array
    std::unordered_map<int, int> indexMap;
    for (int i = 0; i < inLength; ++i) {
        indexMap[inorder[i]] = i;
    }
    
    return buildTreeHelper(postorder, inorder, 0, inLength - 1, 0, postLength - 1, indexMap);
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}
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

BinaryTreeNode<int>* buildTreeHelper(int *pre,int *in,int inS,int inE,int preS,int preE){
    if(inS>inE) return NULL;
    int rootData = pre[preS];
    int rIndex=-1;
    for(int i=inS;i<=inE;++i){
        if(in[i]==rootData){
            rIndex=i;
            break;
        }
    }
    //Left Subtree
    int l_in_s=inS;
    int l_in_e=rIndex-1;
    int l_pre_s=preS+1;
    int l_pre_e=l_in_e - l_in_s + l_pre_s;
    //Right Subtree
    int r_in_s=rIndex+1;
    int r_in_e=inE;
    int r_pre_s=l_pre_e + 1;
    int r_pre_e=preE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(pre,in , l_in_s , l_in_e , l_pre_s , l_pre_e);
    root->right = buildTreeHelper(pre,in , r_in_s , r_in_e , r_pre_s , r_pre_e);
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    if(inLength!=preLength) return NULL;
    buildTreeHelper(preorder,inorder,0,inLength-1,0,preLength-1);
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
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}
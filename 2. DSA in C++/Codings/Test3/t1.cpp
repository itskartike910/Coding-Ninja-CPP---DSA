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

bool isCousin(BinaryTreeNode<int>* root, int p, int q) {
    //Code Here
    if (!root)
        return false;
    
    queue<pair<BinaryTreeNode<int>*, BinaryTreeNode<int>*>> qNodes; // Node, Parent
    qNodes.push({root, nullptr});
    
    int pLevel = 0, qLevel = 0;
    BinaryTreeNode<int>* pParent = nullptr;
    BinaryTreeNode<int>* qParent = nullptr;
    
    while (!qNodes.empty()) {
        int levelSize = qNodes.size();
        for (int i = 0; i < levelSize; ++i) {
            BinaryTreeNode<int>* node = qNodes.front().first;
            BinaryTreeNode<int>* parent = qNodes.front().second;
            qNodes.pop();
            
            if (node->data == p) {
                pLevel = levelSize;
                pParent = parent;
            }
            
            if (node->data == q) {
                qLevel = levelSize;
                qParent = parent;
            }
            
            if (node->left)
                qNodes.push({node->left, node});
            if (node->right)
                qNodes.push({node->right, node});
        }
        
        if (pLevel > 0 && qLevel > 0)
            break;
    }
    
    return pLevel == qLevel && pParent != qParent;
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
			q.pop();
			if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if(isCousin(root, n1, n2)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }
}

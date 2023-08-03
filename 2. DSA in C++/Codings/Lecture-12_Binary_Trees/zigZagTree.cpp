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
/**********************************************************
	Following is the Binary Tree Node class structure

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

***********************************************************/

#include<vector>
void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(!root) return ;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);

    vector<vector<int>> vec;
    vector<int> v;
    while(!q.empty()){
        BinaryTreeNode<int> *t = q.front();
        q.pop();
        if (t == NULL) {
            vec.push_back(v);
            v.clear();
            if (q.empty()) {
                break;
            }
            // cout << endl;
            q.push(NULL);
            continue;
        }
        v.push_back(t->data);
        // cout<<t->data<<" ";
        if(t->left){
            q.push(t->left);
        }
        if(t->right){
            q.push(t->right);
        }
    }
    //cout<<vec.size()<<endl;
    for(int i=0;i<vec.size();i++){
        if(i%2==0){
            for(int j=0;j<vec[i].size();j++){
                cout<<vec[i][j]<<" ";
            }
        }
        else{
            for(int j=vec[i].size()-1;j>=0;j--){
                cout<<vec[i][j]<<" ";
            }
        }
        cout<<endl;
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
    zigZagOrder(root);
}
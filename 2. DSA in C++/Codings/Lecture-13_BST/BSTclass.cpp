#include <iostream>
using namespace std;

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

// #include "solution.h"

#include <queue>
class BST {
    // Define the data members
    BinaryTreeNode<int> *root;
    public:
    BST() { 
        // Implement the Constructor
        root=NULL ;
    }


	/*----------------- Private Functions of BST -----------------*/
    private:
    void printIter(BinaryTreeNode<int> *root){
        queue<BinaryTreeNode<int> *> q;
        q.push(root);
        while(!q.empty()){
            BinaryTreeNode<int> * t = q.front();
            q.pop();
            cout<<t->data<<":";
            if(t->left){
                q.push(t->left);
                cout<<"L:"<<t->left->data<<",";
            }
            if(t->right){
                q.push(t->right);
                cout<<"R:"<<t->right->data;
            }
            cout<<endl;
        }
    }

    // void printRec(BinaryTreeNode<int>* root){
    //     if (!root ) {
    //         return;
    //     }
    //     cout<<root->data<<":";
    //     if(root->left){
    //         cout<<"L:"<<root->left->data<<",";
    //         printRec(root->left);
    //     }
    //     if(root->right){
    //         cout<<"R:"<<root->right->data;
    //         printRec(root->right);
    //     }
    //     cout<<endl;
    // }

    bool searchPrivate(BinaryTreeNode<int> *root,int data){
        if(!root) return false;
        if(root->data==data) return true;
        else if(root->data>data) return searchPrivate(root->left,data);
        else return searchPrivate(root->right,data);
        // bool left = searchPrivate(root->left,data);
        // bool right = searchPrivate(root->right,data);
        // return left || right;
    }

    BinaryTreeNode<int> *deleteData(BinaryTreeNode<int> *root,int data){
        if(!root) return NULL;
        if(data<root->data){
            root->left  = deleteData(root->left,data);
            return root;
        }
        else if(data>root->data){
            root->right  = deleteData(root->right,data);
            return root;
        }
        else{
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left==NULL){
                BinaryTreeNode<int> *temp = root->right;
                root->right=NULL;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                BinaryTreeNode<int> *temp = root->left;
                root->left=NULL;
                delete root;
                return temp;
            }
            else{
                BinaryTreeNode<int> *temp = root->right;
                while(temp->left!=NULL){
                    temp = temp->left;
                }
                int val = temp->data;
                root->data =val ;
                root->right = deleteData(root->right,val);
                return  root;                
            }
        }
    }

    BinaryTreeNode<int> *insertHelper(BinaryTreeNode<int> *root,int x){
        if(!root){
            BinaryTreeNode<int> *node = new BinaryTreeNode<int>(x);
            return node;
        }
        if(x<=(root->data)){
            root->left=insertHelper(root->left,x);
        }
        else{
            root->right=insertHelper(root->right,x);
        }
        return root;
    }

	/*----------------- Public Functions of BST -----------------*/
    public:
    void remove(int data) { 
        // Implement the remove() function 
        this->root = deleteData(this->root, data);
    }
    void print() { 
        // Implement the print() function
        printIter(this->root);
        // printRec(this->root);
    }

    void insert(int data) { 
        // Implement the insert() function 
        this->root = insertHelper(this->root,data);
    }

    bool search(int data) {
		// Implement the search() function 
        return searchPrivate(this->root,data);
    }
};

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

// #include "solution.h"

// TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
//     // Write your code here
//     if(!root) return NULL;
//     TreeNode<int> *t=NULL,*temp=NULL;
//     for(int i=0;i<root->children.size();i++){
//         temp=getSecondLargestNode(root->children[i]);
//     }
//     if(root->data > t->data) return root;
//     if(temp!=NULL && (t==NULL || temp->data > t->data)) t = temp;
//     return t;
// }


void helper(TreeNode<int> *root,TreeNode<int> **first,TreeNode<int> **second){
    if(root==NULL)
    {
        return;
    }
    if(!(*first)){
        *first=root;
    }
    else if(root->data>(*first)->data){
        *second=*first;
        *first=root;
    }
    else if(!(*second)|| root->data>(*second)->data)
        *second=root;
    for(int i=0;i<root->children.size();i++)
        helper(root->children[i],first,second);
}
TreeNode <int>* getSecondLargestNode(TreeNode<int> *root) {
    TreeNode<int> *second=NULL;
    TreeNode<int> *first=NULL;
    helper(root,&first,&second);
    if(second==NULL)
        return NULL;
    if(first->data==second->data)
        return NULL;
    return second;
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}
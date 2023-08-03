#include <iostream>
#include <queue>
#include <stack>
#include <vector>
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

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here
    if(!root) return NULL;
    TreeNode<int> *t=NULL;
    if(root->data>x){
        t=root;
        return t;
    }
    for(int i=0;i<root->children.size();i++){
        t = getNextLargerElement(root->children[i],x);
        if(t!=NULL && t->data>=x ) return t;
    }
    return t;
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
    int x;
    cin >> x;
    TreeNode<int>* ans = getNextLargerElement(root, x);

    if (ans != NULL) {
        cout << ans->data;
    }
}
#include <iostream>
#include <vector>
#include <queue>
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

void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int> *> q;
    if (!root) return ;
    q.push(root);
    while(!q.empty()){
        TreeNode<int> *node = q.front();
        cout << node -> data<<":";
        q.pop();
        int size=(node->children).size();
        for(int i=0;i<size;i++){
            cout<<(node->children)[i]->data;
            if(i!=size-1) cout<<",";
            q.push((node->children)[i]);
        }
        cout<<endl;
    }
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
    printLevelWise(root);
}
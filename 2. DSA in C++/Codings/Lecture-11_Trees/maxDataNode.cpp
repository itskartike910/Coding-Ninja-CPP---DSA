#include <iostream>
#include <queue>
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


TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    if (!root) return NULL;
    TreeNode<int> * t = root;
    queue<TreeNode<int> *> q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode<int> *node = q.front();
        q.pop();
        int size=(node->children).size();
        for(int i=0;i<size;i++){
            if((t->data)<((node->children)[i]->data)){
                t=(node->children)[i];
            }
            q.push((node->children)[i]);
        }
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
    TreeNode<int>* ans = maxDataNode(root);

    if (root != NULL) {
        cout << ans->data;
    }
}
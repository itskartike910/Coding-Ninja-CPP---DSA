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

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
    if(root1->data!=root2->data) return false;
    TreeNode<int> * t1 = root1;
    TreeNode<int> * t2 = root2;
    queue<TreeNode<int> *> q1;
    queue<TreeNode<int> *> q2;
    q1.push(root1);
    q2.push(root2);
    vector<int> a1,a2;
    a1.push_back(root1->data);
    a2.push_back(root2->data);

    while(!q1.empty() && !q2.empty()){
        TreeNode<int> *node1 = q1.front();
        TreeNode<int> *node2 = q2.front();
        q1.pop();
        q2.pop();
        int size1=(node1->children).size();
        int size2=(node2->children).size();
        if(size1!=size2) return false;
        for(int i=0;i<size1;i++){
            q1.push((node1->children)[i]);
            q2.push((node2->children)[i]);

            a1.push_back(node1->children[i]->data);
            a2.push_back(node2->children[i]->data);
        }
    }
    for(int i=0;i<a1.size();i++){
        if(a1[i]!=a2[i]) return false;
    }
    return true;
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
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");
}
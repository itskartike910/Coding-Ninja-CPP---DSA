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


TreeNode<int>* maxSumNodeHelper(TreeNode<int>* root, int& maxSum) {
    if (root == nullptr)
        return nullptr;

    int sum = root->data;
    for (TreeNode<int>* child : root->children) {
        sum += child->data;
    }

    if (sum > maxSum) {
        maxSum = sum;
        return root;
    }

    TreeNode<int>* maxSumNode = nullptr;
    for (TreeNode<int>* child : root->children) {
        TreeNode<int>* childNode = maxSumNodeHelper(child, maxSum);
        if (childNode != nullptr) {
            maxSumNode = childNode;
        }
    }

    return maxSumNode;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    int maxSum = 0;
    return maxSumNodeHelper(root, maxSum);
}



// TreeNode<int>* maxSumNode(TreeNode<int>* root) {
//     // Write your code here

// }

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

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}
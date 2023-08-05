#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
// #include "solution.h"

/*Method 1*/

// bool isBSTUtil(BinaryTreeNode<int> *root, int minValue, int maxValue) {
//     if (root == NULL) {
//         return true;
//     }
//     int nodeValue = root->data;
//     if (nodeValue <= minValue || nodeValue >= maxValue) {
//         return false;
//     }
//     bool leftIsBST = isBSTUtil(root->left, minValue, nodeValue);
//     bool rightIsBST = isBSTUtil(root->right, nodeValue, maxValue);

//     return leftIsBST && rightIsBST;
// }

// bool isBST(BinaryTreeNode<int> *root) {
//     return isBSTUtil(root, INT_MIN, INT_MAX);
// }

/*Method 2*/

// int minimum(BinaryTreeNode<int> *root){
//     if(!root) return INT_MAX;
//     return min(root->data , min(minimum(root->left),minimum(root->right)));
// }
// int maximum(BinaryTreeNode<int> *root){
//     if(!root) return INT_MIN;
//     return max(root->data , max(minimum(root->left),minimum(root->right)));
// }

// bool isBST(BinaryTreeNode<int> *root) {
//     if(!root) return true;
//     int leftMax = maximum(root->left);
//     int rightMin = minimum(root->right);

//     bool ans = (root->data > leftMax) && (root->data < rightMin) && isBST(root->left) && isBST(root->right);
//     return ans;
// }

/*Method 3*/

class IsBSTReturn
{ // Class to store data for each node of tree
public:
    bool isBST;
    int minimum;
    int maximum;
};

IsBSTReturn isBST2(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {                        // Base Case
        IsBSTReturn output;  // Object created for class and then values initialized
        output.isBST = true; // Empty tree is a BST
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    IsBSTReturn leftOutput = isBST2(root->left);   // Left subtree Recursive call
    IsBSTReturn rightOutput = isBST2(root->right); // Right subtree Recursive call
    // Small Calculation
    // Minimum and maximum values figured out side-by-side preventing extra traversals
    int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
    // Checking out for the subtree if it’s a BST or not
    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;
    // Assigning values to the output class object
    IsBSTReturn output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = isBSTFinal;
    return output;
}

    BinaryTreeNode<int> *takeInput()
    {
        int rootData;
        cin >> rootData;
        if (rootData == -1)
        {
            return NULL;
        }
        BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
        queue<BinaryTreeNode<int> *> q;
        q.push(root);
        while (!q.empty())
        {
            BinaryTreeNode<int> *currentNode = q.front();
            q.pop();
            int leftChild, rightChild;

            cin >> leftChild;
            if (leftChild != -1)
            {
                BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
                currentNode->left = leftNode;
                q.push(leftNode);
            }

            cin >> rightChild;
            if (rightChild != -1)
            {
                BinaryTreeNode<int> *rightNode =
                    new BinaryTreeNode<int>(rightChild);
                currentNode->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }

    //4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    int main()
    {
        BinaryTreeNode<int> *root = takeInput();
        cout << (isBST2(root).isBST ? "true" : "false");
    }
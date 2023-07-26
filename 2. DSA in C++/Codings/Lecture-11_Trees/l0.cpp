#include <iostream>
#include <queue>
#include "Tree.h" // Tree.h file included as told above
using namespace std;

void preorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

int numNodes(TreeNode<int> *root)
{
    if (root == NULL)
    { // Edge case
        return 0;
    }
    int ans = 1; // To store total count
    for (int i = 0; i < root->children.size(); i++)
    {                                       // iterating over children vector
        ans += numNodes(root->children[i]); // recursively storing the count
        // of children’s children nodes.
    }
    return ans; // ultimately returning the final answer
}

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
    { // Edge case
        return;
    }
    if (k == 0)
    { // Base case: when the depth is 0
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {                                            // Iterating over each child and
        printAtLevelK(root->children[i], k - 1); // recursively calling with with 1
        // depth less
    }
}

TreeNode<int> *takeInputLevelWise()
{ // Function to take level-wise input
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes; // Queue declared of type TreeNode
    pendingNodes.push(root);             // Root data pushed into queue at first
    while (pendingNodes.size() != 0)
    {                                                // Runs until the queue is not empty
        TreeNode<int> *front = pendingNodes.front(); // stores front of queue
        pendingNodes.pop();                          // deleted that front node stored previously
        cout << "Enter num of children of " << front->data << endl;
        int numChild;
        cin >> numChild; // get the number of child nodes
        for (int i = 0; i < numChild; i++)
        { // iterated over each child node to
            // input it
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child); // Each child node is pushed
            // into the queue as well as the list of child nodes as it is taken input so that next
            //  time we can take its children as input while we kept moving in the level-wise
            //  fashion
            pendingNodes.push(child);
        }
    }
    return root; // Finally returns the root node
}

TreeNode<int> *takeInput()
{                 // Function that returns root node after taking input
    int rootData; // To store root data
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    // Dynamically created a root node and initialized with constructor
    int n; // To store number of children of the node
    cout << "Enter num of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput(); // Input taken recursively for
        // each child node of the current node
        root->children.push_back(child); // Each child node is inserted into
        // the list of children nodes’
    }
    return root;
}

void printTree(TreeNode<int> *root)
{ // Function to print the tree that takes the
    // root node as its argument
    if (root == NULL)
    { // Base case
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    { // Traversing over the vector of
        // its child nodes and printing each of it
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {                                 // Now recursively calling print
        printTree(root->children[i]); // function over each child
    }
}

void deleteTree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

int main()
{
    TreeNode<int> *root = takeInput();
    preorder(root);
    // TODO : Delete tree
}

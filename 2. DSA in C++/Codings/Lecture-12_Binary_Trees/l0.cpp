#include <bits/stdc++.h>
using namespace std;
#include "BTree.h"

void printTree(Btree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << "L->" << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R->" << root->right->data << " ";
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

Btree<int> *takeInput()
{
    int rootData;
    cout << "Enter Data: ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    Btree<int> *root = new Btree<int>(rootData);
    Btree<int> *leftChild = takeInput();
    Btree<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

Btree<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    queue<Btree<int> *> q;
    Btree<int> *root = new Btree<int>(rootData);
    q.push(root);
    while (!q.empty())
    {
        Btree<int> *t = q.front();
        q.pop();
        int leftd, rightd;
        cout << "Enter left child of " << t->data << ": ";
        cin >> leftd;
        if (leftd != -1)
        {
            Btree<int> *leftChild = new Btree<int>(leftd);
            t->left = leftChild;
            q.push(leftChild);
        }
        cout << "Enter right child of " << t->data << ": ";
        cin >> rightd;
        if (rightd != -1)
        {
            Btree<int> *rightChild = new Btree<int>(rightd);
            t->right = rightChild;
            q.push(rightChild);
        }
    }
    return root;
}

int numNodes(Btree<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}


//Height and Diameter of a Binary Tree--->> Not Optimal
int height(Btree<int> *root)
{ // Function to calculate height of tree
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameter(Btree<int> *root)
{ // Function for calculating diameter
    if (root == NULL)
    { // Base case
        return 0;
    }
    int option1 = height(root->left) + height(root->right); // Option 1
    int option2 = diameter(root->left);                     // Option 2
    int option3 = diameter(root->right);                    // Option 3
    return max(option1, max(option2, option3));             // returns the maximum value
}

//Optimal Height and diameter of a Binary Tree
pair<int,int> heightDiameter(Btree<int> *root){
    if(!root){
        pair <int,int > p ;
        p.first=p.second=0;
        return p;
    }
    pair<int,int> leftSub = heightDiameter(root->left);
    pair<int,int> rightSub = heightDiameter(root->right);

    int lh = leftSub.first;
    int ld = leftSub.second;
    int rh = rightSub.first;
    int rd = rightSub.second;

    int height = 1 + max(lh,rh);
    int diameter = max(lh + rh , max(ld,rd));

    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

int main()
{
    // Btree<int> *root = takeInput();
    Btree<int> *root = takeInputLevelWise();
    printTree(root);
    pair<int,int> p = heightDiameter(root);
    cout<<"Height = "<<p.first<<" Diameter = "<<p.second<<endl;
    return 0;
}
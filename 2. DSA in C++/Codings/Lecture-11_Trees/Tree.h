#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;                         // To store data
    vector<TreeNode<T> *> children; // To store children for each node
    TreeNode(T data)
    { // Constructor to initialize data
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {                       // We will call delete on all its
            delete children[i]; // children which will invoke
        }                       // corresponding destructor and ultimately delete the root node itself.
    }
};
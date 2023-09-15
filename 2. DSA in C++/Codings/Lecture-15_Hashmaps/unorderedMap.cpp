#include<bits/stdc++.h> 
using namespace std;
template <typename V>

class MapNode{ // class for linked list.
public:
    string key;    // to store key of type string
    V value;       // to store value of type template
    MapNode *next; // to store the next pointer
    MapNode(string key, V value)
    { // constructor to assign values
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode()
    { // Destructor to delete the node.
        delete next;
    }
};

class OurMap
{
};

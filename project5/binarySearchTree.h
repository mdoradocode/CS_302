#pragma once 
#include <iostream>
#include "binaryNode.h"

using namespace std;

template <typename t> class binaryNode;
template <typename t, class binaryNode> class binarySearchTree;
template < typename t, class binaryNode> std :: ostream & operator<<(std::ostream &os, const binarySearchTree<t,binaryNode> &obj);


template <typename t, class binaryNode>
class binarySearchTree
{
    friend std::ostream &operator<< <>(std::ostream & os, 
                    const binarySearchTree<t,binaryNode> & obj);
    public:
     //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    binarySearchTree();
    binarySearchTree(const t& rootItem);

    
    //------------------------------------------------------------
    // Places a given new node at its proper position in this binary
    // search tree.
    binaryNode *placeNode(binaryNode *subTreePtr, binaryNode *newNode);

    // Removes the given target value from the tree while maintaining a
    // binary search tree.
    binaryNode * removeValue(binaryNode * subTreePtr, const t target, bool& isSuccessful);

    // Removes a given node from a tree while maintaining a binary search tree.
    binaryNode * removeNode(binaryNode * nodePtr);

    // Removes the leftmost node in the left subtree of the node
    // pointed to by nodePtr.
    // Sets inorderSuccessor to the value in this node.
    // Returns a pointer to the revised subtree.
    binaryNode * removeLeftmostNode(binaryNode *subTreePtr, t& inorderSuccessor);

    // Returns a pointer to the node containing the given value,
    // or nullptr if not found.
    binaryNode * findNode(binaryNode * treePtr, const t& target);

    //------------------------------------------------------------
    // Public Methods Section.
    //------------------------------------------------------------
    bool isEmpty();
    int getHeight(binaryNode * nodePtr);
    int startGettingHeight();
    int getNumberOfNodes();

    binaryNode * getRootPtr();
    t getRootData();
    void setRootData(const t& newData);

    bool add(const t& newEntry);
    bool remove(const t& target);
    void clear();

    t getEntry(const t& anEntry);
    bool contains(const t& anEntry);

    //------------------------------------------------------------
    // Public Traversals Section.
    //------------------------------------------------------------
    void preorderTraverse( binaryNode *node);
    void inorderTraverse( binaryNode *node);
    void postorderTraverse( binaryNode *node);
    //------------------------------------------------------------
    // Overloaded Operator Section.
    //------------------------------------------------------------
    binarySearchTree<t,binaryNode>& operator=(const binarySearchTree<t,binaryNode>& rightHandSide);

    private:
    binaryNode * rootPtr;
    int nodeCounter;
}; 

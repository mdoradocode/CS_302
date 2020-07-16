#pragma once
#include <iostream>

template<typename t> class binaryNode;
template <typename t, class binaryNode> class binarySearchTree;

template <typename t>
class binaryNode{
    friend class binarySearchTree<t,binaryNode>;
    public:
    binaryNode(const binaryNode *left, const binaryNode *right, const t data);
    t &getData(); 
    void setData(const t data);
    binaryNode *getLeft();
    binaryNode *getRight();
    void setLeft( binaryNode *left);
    void setRight( binaryNode *right);

    private:
    binaryNode *leftChild;
    binaryNode *rightChild;
    t m_data;
    int dataCount; //This will take care of any duplicates in the tree, but I need to make sure to account for it in the printing part of this program
};
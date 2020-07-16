#include "binaryNode.h"

using namespace std;

template <typename t>
binaryNode<t> :: binaryNode(const binaryNode *left, const binaryNode *right, const t data)
{
    leftChild = NULL;
    rightChild = NULL;
    m_data = data;
}

template <typename t>
t &binaryNode<t> :: getData()
{
    return m_data;
}

template <typename t>
void binaryNode<t> :: setData(const t data)
{
    m_data = data;
}

template <typename t>
binaryNode<t> * binaryNode<t> :: getLeft()
{ 
    return leftChild;
}

template <typename t>
binaryNode<t> * binaryNode<t> :: getRight()
{
    return rightChild;
}

template <typename t>
void binaryNode<t> :: setLeft( binaryNode *left)
{
    leftChild = left;
}

template <typename t>
void binaryNode<t> :: setRight( binaryNode *right)
{
    rightChild = right;
}
#include "binarySearchTree.h"
#include "binaryNode.h"

using namespace std;
//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
template <typename t, class binaryNode> 
binarySearchTree<t,binaryNode> :: binarySearchTree()
{
    rootPtr = NULL;
    nodeCounter = 0;
}

template <typename t, class binaryNode> 
binarySearchTree<t,binaryNode> :: binarySearchTree(const t& rootItem)
{
    rootPtr -> setData(rootItem);
    nodeCounter = 1;
}


//------------------------------------------------------------
// Places a given new node at its proper position in this binary
// search tree.
template <typename t, class binaryNode> 
binaryNode * binarySearchTree<t, binaryNode> :: placeNode(binaryNode *subTreePtr, binaryNode *newNode)
{
    binaryNode *tempPtr;
    if(subTreePtr == NULL)
    {
        return newNode;
    }
    else if(subTreePtr ->getData() > newNode -> getData())
    {
        tempPtr = placeNode(subTreePtr -> getLeft(), newNode);
        subTreePtr -> setLeft(tempPtr);
    }
    else
    {
        tempPtr = placeNode(subTreePtr -> getRight(), newNode);
        subTreePtr -> setRight(tempPtr);
    }
    return subTreePtr;
}

// Removes the given target value from the tree while maintaining a
// binary search tree.
template <typename t, class binaryNode> 
binaryNode * binarySearchTree<t,binaryNode> :: removeValue(binaryNode * subTreePtr, const t target, bool & isSuccessful)
{
    binaryNode *tempPtr;
    if(subTreePtr == NULL)
    {
        isSuccessful = false;
    }
    else if(subTreePtr -> getData() == target)
    {
        if(subTreePtr -> dataCount  > 1){
            subTreePtr -> dataCount--;
            isSuccessful = true;
            
        }
        else
        {
            subTreePtr = removeNode(subTreePtr);  //probably where we want to decrement the counter dealio
            isSuccessful = true;
        }
    }
    else if(subTreePtr ->getData() > target)
    {
        tempPtr = removeValue(subTreePtr ->getLeft(), target, isSuccessful);
        subTreePtr -> setLeft(tempPtr);
    }
    else //subTreePtr ->get()Data < target
    {
        tempPtr = removeValue(subTreePtr ->getRight(), target, isSuccessful);
        subTreePtr ->  setRight(tempPtr);
    }
    return subTreePtr;
}

// Removes a given node from a tree while maintaining a binary search tree.
template <typename t, class binaryNode> 
binaryNode *  binarySearchTree<t,binaryNode> :: removeNode(binaryNode * nodePtr)
{
    binaryNode *theGreatBridge; //I have nothing left in my life
    t successor;
    if(!isEmpty())
    {
        if(nodePtr -> getLeft() == NULL && nodePtr ->getRight() == NULL)
        {
            delete nodePtr;
            return NULL;
        }
        else if((nodePtr -> getLeft() != NULL && nodePtr -> getRight() == NULL) || (nodePtr -> getLeft() == NULL && nodePtr ->getRight() != NULL))
        {
            if(nodePtr -> getLeft() != NULL)
            {
                theGreatBridge = nodePtr -> getLeft();
            }
            else
            {
                theGreatBridge = nodePtr -> getRight();
            }
            delete nodePtr;
            return theGreatBridge;
        }
        else //The Node has two goddamn children
        {
            theGreatBridge = removeLeftmostNode(nodePtr ->getRight(), successor);
            nodePtr -> setRight(theGreatBridge);
            nodePtr -> setData(successor);
            return nodePtr;
        }
    }
}

// Removes the leftmost node in the left subtree of the node
// pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree.
template <typename t, class binaryNode> 
binaryNode *  binarySearchTree<t,binaryNode> :: removeLeftmostNode(binaryNode *subTreePtr, t& inorderSuccessor)// think we are stuck here something is amissds
{
    binaryNode *temp;
    if(subTreePtr -> getLeft() == NULL){
        inorderSuccessor =  subTreePtr -> getData();
        return removeNode(subTreePtr);
    }
    else
    {
        temp = removeLeftmostNode(subTreePtr -> getLeft(), inorderSuccessor);
        subTreePtr -> setLeft(temp);
        return subTreePtr;
    }
}

// Returns a pointer to the node containing the given value,
// or nullptr if not found.
template <typename t, class binaryNode> 
binaryNode *binarySearchTree<t,binaryNode> :: findNode(binaryNode * treePtr, const t& target)
{
    if(treePtr == NULL)
    {
        return NULL;
    }
    else if(treePtr -> getData() == target)
    {
        return treePtr;
    }
    else if(treePtr -> getData() > target)
    {
        return findNode(treePtr -> getLeft(), target);
    }
    else
    {
        return find(treePtr -> getRight(), target);
    }
}

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
template <typename t, class binaryNode> 
bool binarySearchTree<t,binaryNode> :: isEmpty()
{
    if(rootPtr == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

template <typename t, class binaryNode> 
int binarySearchTree<t,binaryNode> :: startGettingHeight()
{
    if(this ->isEmpty())
    {
        return 0;
    }
    else
    {
        return getHeight(this -> rootPtr);
    }
    
}
template <typename t, class binaryNode> 
int binarySearchTree<t,binaryNode> :: getHeight(binaryNode *nodePtr)
{
    int rightH = 0;
    int leftH = 0;
    if(nodePtr -> getLeft() != NULL)
    {
        leftH = this -> getHeight(nodePtr ->getLeft());
    }
    if(nodePtr -> getRight() != NULL)
    {
        rightH = this -> getHeight(nodePtr -> getRight());
    }
    if(leftH > rightH)
    {
        return leftH+1;
    }
    else
    {
        return rightH+1;
    }
}

template <typename t, class binaryNode> 
int binarySearchTree<t,binaryNode> :: getNumberOfNodes()
{
    return nodeCounter;
}

template <typename t, class binaryNode> 
t binarySearchTree<t,binaryNode> :: getRootData()
{
    return rootPtr -> getData();
}

template <typename t, class binaryNode> 
void binarySearchTree<t,binaryNode> :: setRootData(const t& newData)
{
    rootPtr -> setData(newData);
}

template <typename t, class binaryNode> 
bool binarySearchTree<t,binaryNode> :: add(const t& newEntry)
{
    binaryNode *newNode = new binaryNode(NULL, NULL, newEntry);
    this  -> rootPtr = placeNode(rootPtr, newNode);
    nodeCounter++;
    return true;
}

template <typename t, class binaryNode> 
bool binarySearchTree<t,binaryNode> :: remove(const t& target)
{
    bool isSuccessful = false;
    rootPtr = removeValue(rootPtr, target, isSuccessful);
    if(isSuccessful == true && nodeCounter > 0)
    {
        nodeCounter--;
    }
    return isSuccessful;
}

template <typename t, class binaryNode> 
void binarySearchTree<t,binaryNode> :: clear() //This probably doesnt work
{
    while(nodeCounter != 0){
        removeNode(rootPtr);
    }
}

template <typename t, class binaryNode> 
t binarySearchTree<t,binaryNode> :: getEntry(const t& anEntry){}//Idk if this is useful, keeping it around until i get my traversals done

template <typename t, class binaryNode> 
bool binarySearchTree<t,binaryNode> :: contains(const t& anEntry) 
{
    binaryNode *temp = this ->findNode(rootPtr,anEntry);
    if(temp -> getData() == anEntry)
    {
        return true;
    }
    else{
        return false;
    }
}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
template <typename t, class binaryNode> 
void binarySearchTree<t,binaryNode> :: preorderTraverse( binaryNode *node)
{
    if(node == NULL)
    {
        return;
    }
    cout << node ->getData() << " ";
    preorderTraverse(node -> getLeft());
    preorderTraverse(node -> getRight());

}

template <typename t, class binaryNode> 
void binarySearchTree<t,binaryNode> :: inorderTraverse( binaryNode *node)
{
    if(node == NULL)
    {
        return;
    }
    inorderTraverse(node -> getLeft());
    cout << node -> getData() << " ";
    inorderTraverse(node -> getRight());
}

template <typename t, class binaryNode> 
void binarySearchTree<t,binaryNode> :: postorderTraverse( binaryNode *node)
{
    if(node == NULL)
    {
        return;
    }
    postorderTraverse(node -> getLeft());
    postorderTraverse(node -> getRight());
    cout << node ->getData() << " ";
}
template <typename t, class binaryNode> 
binaryNode * binarySearchTree<t, binaryNode> :: getRootPtr()
{
    return rootPtr;
}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
template <typename t, class binaryNode> 
binarySearchTree<t,binaryNode> &binarySearchTree<t, binaryNode> :: operator=(const binarySearchTree<t,binaryNode>& rightHandSide){}

template <typename t, class binaryNode> 
std::ostream &operator<< (std::ostream & os, const binarySearchTree<t,binaryNode> & obj){}
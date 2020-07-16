/* Binary Search Tree: This project makes 100 NON UNIQUE numbers and fills a binary search tree with them. The large bug is that the clear function doesnt work,
however,  the remove function does, so id call that a win. Now you may ask yourself, why would you make the numbers non-unique meaning that duplicate numbers 
and nodes become an issue? Well let me give you two facts about duplicate numbers:
1) They are hard to account for
2) They suck super hard
Now let me give you two facts about duplicate nodes:
1) They are hard to account for
2) They suck super hard
With this conclusion I decided that duplicates in this scenario are hard to account for and suck super hard, so I thought about how to get rid of them without following 
the assignment out line, because I guess I cant help myself to making school harder. NONE THE LESS, I simply got rid of duplicate numbers and nodes to free myself of 
the difficulty of tracking and aforementioned sucking. instead, when a number is a duplicate, it increments a counter in each node that tells if their is more than one of an 
integer and the node will only delete if there is zero counts of an integer in a node. Pretty G.
In summary, please dont mark me down, i just wanted to go an extra mile.
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "binarySearchTree.h"
#include "binarySearchTree.cpp"
#include "binaryNode.h"
#include "binaryNode.cpp"

int main()
{
    binarySearchTree<int, binaryNode<int>> theTree;
    int tempArray[100];
    srand(time(NULL));
    for(size_t i = 0; i <= 99; i++){
        int holder = rand() % 200; 
        tempArray[i] = holder;
    }
    int index = 0;
    while(index <= 99)
    {
        theTree.add(tempArray[index]);
        index++;
    }
    cout << "In order Traversal: ";
    theTree.inorderTraverse(theTree.getRootPtr());
    cout << endl << endl;
    cout << "PostOrderTraversal: ";
    theTree.postorderTraverse(theTree.getRootPtr());
    cout << endl << endl;
    cout << "Pre Order Traversal: ";
    theTree.preorderTraverse(theTree.getRootPtr());
    cout << endl << endl;
    cout << "The height is: " << theTree.startGettingHeight() << endl;
}
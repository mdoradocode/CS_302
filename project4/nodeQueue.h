#pragma once 
#include <iostream>
#include "Node.h"

using namespace std;

template < typename t> class Node;
template <typename t, class Node> class nodeQueue;
template < typename t, class Node> std :: ostream & operator<<(std::ostream &os, const nodeQueue<t,Node> &obj);

template <typename t, class Node>
class nodeQueue{    
    friend std::ostream &operator<< <>(std::ostream & os, 
                                            const nodeQueue<t,Node> & obj);
    public:
    nodeQueue();
    nodeQueue(const nodeQueue<t, Node> & cpy);
    ~nodeQueue();


    Node & getBack();
    Node & getFront();
    void push(const t & arrive, const t & transaction);
    void pop();
    int size() const;
    bool IsEmpty() const;
    Node * peek();
    void clear();
    void serialize(std::ostream &os) const;


    private:
    Node *back;
    Node *front;
    int queueCount;
};



#pragma once 
#include <iostream>
#include "Node.h"

using namespace std;

template < typename t> class Node;
template <typename t, class Node> class NodeStack;
template < typename t, class Node> std :: ostream & operator<<(std::ostream &os, const NodeStack<t,Node> &obj);

template <typename t, class Node>
class NodeStack{    
    friend std::ostream &operator<< <>(std::ostream & os, 
                                            const NodeStack<t,Node> & obj);
    public:
    NodeStack();
    NodeStack(const NodeStack<t, Node> & cpy);
    ~NodeStack();


    Node & top();
    void push(const t & value);
    void pop();
    int size() const;
    bool IsEmpty() const;
    t & peek();
    void clear();
    void serialize(std::ostream &os) const;


    private:
    Node *m_top;

};
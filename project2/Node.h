#pragma once
#include <iostream>
#include <cstring>

template<typename t> class Node;
template <typename t, class Node> class NodeStack;

template <typename t>
class Node{
    friend class NodeStack<t,Node>;
    public:
    Node();
    Node(const t &data,  Node *next = NULL);
    Node(const Node &cpy);
    t &getData();
    Node * getNext();

    private:
    Node *m_next;
    t m_data;
};
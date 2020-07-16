#pragma once
#include <iostream>
#include <cstring>

template<typename t> class Node;
template <typename t, class Node> class nodeQueue;

template <typename t>
class Node{
    friend class nodeQueue<t,Node>;
    public:
    Node();
    Node(const t & arrive, const t & transaction,  Node *next = NULL);
    Node(const Node &cpy);
    t &getArrive();
    t &getTransaction();
    Node *getNext();

    private:
    Node *m_next;
    t arrive;
    t transaction;
};
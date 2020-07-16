#include "Node.h"

using namespace std;

template<typename t> class Node;
template <typename t, class Node> class NodeStack;

template <typename t>
Node<t> :: Node(): m_next(NULL){;}

template <typename t>
Node<t> :: Node(const t &data,  Node<t> *next): m_next(next), m_data(data)
{;}

template <typename t>
Node<t> :: Node(const Node<t> &cpy): m_data(cpy.m_data), m_next(cpy.m_next){;}

template <typename t>
t &Node<t> :: getData(){return m_data;}

template <typename t>
Node<t> * Node<t> :: getNext(){
    return m_next;
}
#include "Node.h"

using namespace std;

template<typename t> class Node;
template <typename t, class Node> class NodeStack;

template <typename t>
Node<t> :: Node(): m_next(NULL){;}

template <typename t>
Node<t> :: Node(const t &arrive, const t & transaction,  Node<t> *next): m_next(next), arrive(arrive), transaction(transaction){;}

template <typename t>
Node<t> :: Node(const Node<t> &cpy): arrive(cpy.arrive), transaction(cpy.transaction), m_next(NULL){;} //Careful

template <typename t>
t &Node<t> :: getArrive(){return arrive;}

template <typename t>
t &Node<t> :: getTransaction(){return transaction;}

template <typename t>
Node<t> * Node<t> :: getNext(){ return m_next;}
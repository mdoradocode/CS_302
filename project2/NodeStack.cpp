#include "NodeStack.h"
#include "Node.h"

using namespace std;

template <typename t, class Node> 
NodeStack<t,Node> :: NodeStack(): m_top(NULL){}


template <typename t, class Node>
NodeStack<t,Node> :: NodeStack(const NodeStack<t, Node> & other){
    m_top = new Node(other.m_top -> getData(), NULL);
    Node *otherCpy = other.m_top;
    Node *newCpy = m_top;
    while(otherCpy != NULL){
        newCpy ->m_next = new Node(otherCpy -> getData(), NULL);
        newCpy = newCpy ->m_next;
        otherCpy = otherCpy->m_next;
    }
}

template <typename t, class Node>
NodeStack<t,Node> :: ~NodeStack(){
    clear();
}

template <typename t, class Node>
Node & NodeStack<t,Node> ::  top(){
    return *m_top;
}

template <typename t, class Node>
void  NodeStack<t,Node> :: push(const t & value){
    if(!IsEmpty()){
        Node * temp = new Node(value, NULL);
        temp->m_next = m_top;
        m_top = temp;
    }
    else{
        m_top = new Node(value, NULL);
    }
}

template <typename t, class Node>
void NodeStack<t,Node> :: pop(){
    Node *topNode = m_top;
    m_top = m_top ->m_next;
    delete [] topNode;
}

template <typename t, class Node>
int NodeStack<t,Node> :: size() const{
    int i = 0; 
    Node *temp = m_top;
    while(temp ->m_next != NULL){
        i++;
        temp = temp ->m_next;
    }
    return i;
}

template <typename t, class Node>
bool NodeStack<t,Node> :: IsEmpty() const{
    if(m_top == NULL){
        return true;
    }
    else{
        return false;
    }
}

template <typename t, class Node>
t & NodeStack<t,Node> :: peek(){
    return  m_top -> getData();
}

template <typename t, class Node>
void NodeStack<t,Node> :: clear(){
    while(!IsEmpty()){
        pop();
    }
}

template <typename t, class Node>
void NodeStack<t,Node> :: serialize(std::ostream & os) const{ 
    size_t i = 0;
    Node *temp = m_top;
    while(temp != NULL){
        i++;
        os << "#" << i << "  " << temp ->getData() << endl;
        temp = temp ->m_next;
    }
}

template <typename t, class Node>
std::ostream &  operator<< (std::ostream &os, const NodeStack<t,Node> &obj){
    obj.serialize(os);
    return os;
}
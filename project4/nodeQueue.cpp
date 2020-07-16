#include "nodeQueue.h"
#include "Node.h"

using namespace std;


//Constructors
template <typename t, class Node> 
nodeQueue<t,Node> :: nodeQueue(): back(NULL), front(NULL), queueCount(0){}


template <typename t, class Node>
nodeQueue<t,Node> :: nodeQueue(const nodeQueue<t,Node> & cpy){
    Node *cpyTemp = cpy.front;
    front = new Node(cpyTemp -> getArrive(), cpyTemp -> getTransaction(), NULL);
    Node *temp = front;
    back = temp;
    queueCount = 1;
    while(cpyTemp != cpy.front){        
        temp -> m_next = new Node(cpyTemp -> getArrive(), cpyTemp -> getTransaction(), NULL);
        temp =  temp -> m_next;
        back = temp;
        cpyTemp = cpyTemp -> m_next;
        queueCount++;
    }
}

template <typename t, class Node>
nodeQueue<t,Node> :: ~nodeQueue(){
    clear();
}

//Modifiers
template <typename t, class Node>
void  nodeQueue<t,Node> :: push(const t & arrive, const t &transaction){
    if(IsEmpty()){
        back = new Node(arrive, transaction, NULL);
        queueCount++;
        front = back;
    }
    else{
        back ->m_next = new Node(arrive, transaction, NULL);
        back = back ->m_next;
        queueCount++;
    }
}

template <typename t, class Node>
void nodeQueue<t,Node> :: pop(){
        Node *temp = front ->m_next;
        delete[] front;
        front = temp;
        queueCount--;

}

//Queue Attributes
template <typename t, class Node>
Node & nodeQueue<t,Node> :: getBack(){
    return back;
}

template <typename t, class Node>
Node & nodeQueue<t,Node> :: getFront(){
    return front;
}

template <typename t, class Node>
int nodeQueue<t,Node> :: size() const{
    return queueCount;
}

template <typename t, class Node>
bool nodeQueue<t,Node> :: IsEmpty() const{
    if(front == NULL){
        return true;
    }
    return false;
}

template <typename t, class Node>
Node * nodeQueue<t,Node> :: peek(){ //Not sure what this would return exactly
    return front;
}

template <typename t, class Node>
void nodeQueue<t,Node> :: clear(){
    while(front != NULL){
        pop();
    }
}

//Queue Printing
template <typename t, class Node>
void nodeQueue<t,Node> :: serialize(std::ostream & os) const{ 
    size_t i = 0;
    Node *temp = front;
    cout << "#  Arrival  Transaction:" << endl;
    while(temp != NULL){
        i++;
        os << "#" << i << "  " << temp -> getArrive() << ' '  << temp -> getTransaction() << endl;
        temp = temp ->m_next;
    }
}

template <typename t, class Node>
std::ostream &  operator<< (std::ostream &os, const nodeQueue<t,Node> &obj){
    obj.serialize(os);
    return os;
}
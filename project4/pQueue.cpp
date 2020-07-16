#include "pQueue.h"
#include "event.h"

using namespace std;


//Constructors
template <typename t, class event> 
pQueue<t,event> :: pQueue(): back(NULL), front(NULL), queueCount(0){}


template <typename t, class event>
pQueue<t,event> :: pQueue(const pQueue<t, event> & cpy){
    event *cpyTemp = cpy.front;
    front = new event(cpyTemp -> getTime(), cpyTemp ->getLength(), cpyTemp -> getType(), NULL);
    event *temp = front;
    back = temp;
    queueCount = 1;
    while(cpyTemp != cpy.front){        
        temp -> m_next = new event(cpyTemp -> getTime(), cpyTemp ->getLength(), cpyTemp -> getType(), NULL);
        temp =  temp -> m_next;
        back = temp;
        cpyTemp = cpyTemp -> m_next;
        queueCount++;
    }
}

template <typename t, class event>
pQueue<t,event> :: ~pQueue(){
    clear();
}

//Modifiers
template <typename t, class event>
void  pQueue<t,event> :: push(const t & time, const t &length, const int &type){
    if(IsEmpty()){
        back = new event(time, length, type, NULL);
        queueCount++;
        front = back;
    } 
    else{   
        event *tempAhead = front;
        event *tempBehind = front;
        if(time > tempAhead-> getTime()){
            tempAhead = tempAhead -> m_next;
            while(tempAhead != NULL && time > tempAhead -> getTime() ){
                tempAhead = tempAhead ->m_next;        
                tempBehind = tempBehind ->m_next;
            }
            
            tempBehind ->m_next = new event(time, length, type, tempAhead);
            queueCount++;
        }
        else{
            front = new event(time, length,  type, tempAhead);
            queueCount++;
        }
    }
}

template <typename t, class event>
void pQueue<t,event> :: pop(){
    event *temp = front ->m_next;
    delete[] front;
    front = temp;
    queueCount--;
}
//Queue Attributes
template <typename t, class event>
event & pQueue<t,event> :: getBack(){
    return back;
}

template <typename t, class event>
event & pQueue<t,event> :: getFront(){
    return front;
}

template <typename t, class event>
int pQueue<t,event> :: size() const{
    int count = 0;
    event *temp = front;
    while(temp != NULL){
        count++;
        temp = temp ->m_next;
    }
}

template <typename t, class event>
bool pQueue<t,event> :: IsEmpty() const{
    if(front == NULL){
        return true;
    }
    return false;
}

template <typename t, class event>
event *pQueue<t,event> :: peek(){ //Not sure what this would return exactly
    return front;
}

template <typename t, class event>
void pQueue<t,event> :: clear(){
    while(front != NULL){
        pop();
    }
}

//Queue Printing
template <typename t, class event>
void pQueue<t,event> :: serialize(std::ostream & os) const{ 
    size_t i = 0;
    event *temp = front;
    cout << "#  Arrival  Transaction:" << endl;
    while(temp != NULL){
        i++;
        os << "#" << i << "  " << temp -> getTime() << endl;
        temp = temp ->m_next;
    }
}

template <typename t, class event>
std::ostream &  operator<< (std::ostream &os, const pQueue<t,event> &obj){
    obj.serialize(os);
    return os;
}
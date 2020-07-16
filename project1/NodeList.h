#pragma once
#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;


template <class t> std :: ostream &operator<<(std::ostream &os, const NodeList<t>&obj);

template <class t> 
class NodeList{
    friend std::ostream &operator<<  <>(std::ostream &os, const NodeList<t> &obj);
    private:
    Node<t>*m_front;
    Node<t>*m_back;
    public:
    NodeList():m_front(NULL), m_back(NULL){;}

    NodeList(const t &data){
        m_front = new Node<t>(data, NULL);
        m_back = m_front;
    }
    NodeList(const NodeList<t> &cpy){
        Node<t>*temp = m_front;
        Node<t>*tempCpy = cpy.m_front;
        m_front = new Node<t>(cpy.m_front->m_data);
        while(*tempCpy ->m_next != NULL){
            tempCpy  = tempCpy ->m_next;
            temp ->m_next = new Node<t>(tempCpy ->m_data);
            temp  =  temp ->m_next;
        }
        temp ->m_next = NULL;
    }
    ~NodeList(){
        Node<t>*track = m_front;
        Node<t>*kill = m_front;
        while(track != NULL){
            track = track ->m_next;
            delete kill;
            kill = track;
        }
        m_front = NULL;
        m_back = NULL;
    }
    //Track1 leads, track2 tails to assign the m_next of the Node<t>before the deletion, kill is for deletion
    void pop(const t &target){
        Node<t>*kill = m_front;
        Node<t>*track1 = m_front;
        Node<t>*track2 = m_front;
        if(kill ->m_data == target || kill ->m_next != NULL){
            while(kill ->m_data == target){
                m_front = m_front ->m_next;
                track1 = m_front;
                track2 = m_front;
                cout << "test" << endl;
                delete kill;
                kill = m_front;
            }
        }
        track1 = track1 ->m_next;
        kill = track1;
        while(track1 != NULL){// Possibly m_back?
            if(kill->m_data == target){
                track2 ->m_next = track1 ->m_next;
                track1 = track1 ->m_next;
                delete kill;
                kill = track1;
            }
            else{
                track2 = track2 ->m_next;
                track1 = track1 ->m_next;
                kill = track1;
            }
        }
    }

    void push(const t &data){
        if(m_front == NULL){
            m_front = new Node<t>(data);
            m_back = m_front;
        }
        else{
            Node<t>*temp = m_front;
            while(temp ->m_next != NULL){
                temp = temp ->m_next;
            }
            temp ->m_next = new Node<t>(data);
            m_back = temp ->m_next;
        }
    }

    Node<t>&front(){
        return m_front;
    }
    Node<t>&back(){
        return m_back;
    }

    bool isEmpty(){
        if(m_front == NULL){
            return true;
        }
        else{
            return false;
        }
    }
    size_t count(){
        Node<t>*temp = m_front;
        size_t count = 1;
        while(temp ->m_next != NULL){
            temp = temp ->m_next;
            count++;
        }    
        return count;
    }
    void serialize(std::ostream &os)const{
        Node<t>*temp = m_front;
        size_t count = 1;
        while(temp  != NULL){
            os << "Node #" << count << " holds " << temp ->getData() << endl;
            temp = temp ->m_next;
            count++;
        }
    }
    NodeList<t> & operator=(const NodeList<t> &obj){
        Node<t>*temp = m_front;
        Node<t>*tempCpy = obj.m_front;
        m_front = new Node<t>(obj.m_front->m_data);
        while(*tempCpy ->m_next != NULL){
            tempCpy  = tempCpy ->m_next;
            temp ->m_next = new Node<t>(tempCpy ->m_data);
            temp  =  temp ->m_next;
        }
        temp ->m_next = NULL;
    }
};

template <class t> 
std :: ostream &operator<<(std::ostream &os, const NodeList<t> &obj){
    obj.serialize(os);
    return os;
}
#pragma once
#include <iostream>
#include <cstring>

using namespace std;

template <class t>  class NodeList;

template <class t>
class Node{
    friend class NodeList<t>;
    public:
    Node(): m_next(NULL){;}
    Node(const t &data,  Node<t> *next = NULL): m_next(next), m_data(data){;}
    Node(const Node<t> &cpy): m_data(cpy.m_data), m_next(cpy.m_next){;}
    t &getData(){return m_data;}

    private:
    Node<t> *m_next;
    t m_data;
};
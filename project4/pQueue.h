#pragma once 
#include <iostream>
#include "event.h"

using namespace std;

template < typename t> class event;
template <typename t, class event> class pQueue;
template < typename t, class event> std :: ostream & operator<<(std::ostream &os, const pQueue<t,event> &obj);

template <typename t, class event>
class pQueue{    
    friend std::ostream &operator<< <>(std::ostream & os, 
                                            const pQueue<t,event> & obj);
    public:
    pQueue();
    pQueue(const pQueue<t, event> & cpy);
    ~pQueue();


    event & getBack();
    event & getFront();
    void push(const t & time, const t & length, const int &type);
    void pop();
    int size() const;
    bool IsEmpty() const;
    event *peek();
    void clear();
    void serialize(std::ostream &os) const;

    private:
    event *back;
    event *front;
    int queueCount;
};
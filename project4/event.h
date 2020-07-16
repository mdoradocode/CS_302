#pragma once
#include <iostream>
#include <cstring>

template<typename t> class event;
template <typename t, class event> class pQueue;

template <typename t>
class event{
    friend class pQueue<t,event>;
    public:
    event();
    event(const t & Time, const t & Length,  const int & Type, event *Next = NULL);
    event(const event &cpy);
    t &getTime();
    t &getLength();
    int &getType();
    event *getNext();

    private:
    event *m_next;
    int type;
    t time;
    t length;
};

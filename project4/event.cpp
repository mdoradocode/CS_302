#include "event.h"

using namespace std;

template<typename t> class event;
template <typename t, class event> class pQueue;

template <typename t>
event<t> :: event(): m_next(NULL){;}

template <typename t>
event<t> :: event(const t &Time, const t & Length,  const int & Type,  event<t> *Next)
{
    time = Time;
    length = Length;
    type = Type;
    m_next = Next;
}
template <typename t>
event<t> :: event(const event<t> &cpy): time(cpy.time), length(cpy.length), type(cpy.type), m_next(NULL){;} //Careful

template <typename t>
t &event<t> :: getTime(){return time;}

template <typename t>
t &event<t> :: getLength(){return length;}

template <typename t>
event<t> * event<t> :: getNext(){ return m_next;}

template <typename t>
int &event<t> :: getType(){return type;}
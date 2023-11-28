#ifndef LINKEDLIST
#define LINKEDLIST


#include "ListNode.h"

using namespace std;

template <typename Data>
class LinkedList
{
private:
    ListNode<Data>* begin;
    ListNode<Data>* end;
    ListNode<Data>* current;
    ListNode<Data>* previous;

    unsigned int size;

public:
    LinkedList();
    LinkedList(ListNode<Data>* begin, ListNode<Data>* end);

    ListNode<Data>* get_begin() const;
    ListNode<Data>* get_end() const;
    ListNode<Data>* get_current() const;
    ListNode<Data>* get_previous() const;

    unsigned int get_size() const;

    void set_begin(ListNode<Data>* data);
    void set_end(ListNode<Data>* data);
    void set_current(ListNode<Data>* data);
    void set_previous(ListNode<Data>* data);

    bool exists(Data data) const;
    Data get(unsigned int pos) const;
    void set(unsigned int pos, Data data);
    void add(Data data);
    void push(Data data);
    void remove(Data data);

    friend ofstream& operator<< (ofstream& os, const LinkedList<Data> list);
};

#include "LinkedList.cpp"

#endif